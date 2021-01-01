#include <fcntl.h>
#include <stdint.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "mira.h"


//provided by libkernel
int pthread_getthreadid_np();


typedef struct mira_thread_credentials {
  uint32_t state;

  int32_t pid;
  int32_t tid;

  int32_t euid;
  int32_t ruid;
  int32_t suid;
  
  int32_t groups;
  int32_t rgid;
  int32_t sgid;
  
  uint32_t prison;
  uint64_t authid;
  uint64_t caps[4];
  uint64_t attrs[4];
} mira_thread_credentials_t;

#define CAPS_MAX  0xFFFFFFFFFFFFFFFFULL

#define MIRA_INOUT_GET 0
#define MIRA_INOUT_SET 1

#define IOCTL_INOUT_CREDENTIALS 0xc0704d01


int
mira_get_credentials(mira_thread_credentials_t *cred) {
  int fd;
  int rc;
  
  memset(cred, 0, sizeof(mira_thread_credentials_t));
  cred->state = MIRA_INOUT_GET;
  cred->pid = getpid();
  cred->tid = pthread_getthreadid_np();
  
  if((fd = open("/dev/mira", 0, O_RDWR)) < 0) {
    return -1;
  }

  rc = ioctl(fd, IOCTL_INOUT_CREDENTIALS, cred);
  close(fd);

  return rc;
}


static int
mira_set_credentials(const mira_thread_credentials_t *cred) {
  mira_thread_credentials_t cred_copy;
  int fd;
  int rc;
  
  memcpy(&cred_copy, cred, sizeof(mira_thread_credentials_t));
  cred_copy.state = MIRA_INOUT_SET;

  if(!cred_copy.pid) {
    cred_copy.pid = getpid();
  }

  if(!cred_copy.tid) {
    cred_copy.tid = pthread_getthreadid_np();
  }
  
  if((fd = open("/dev/mira", 0, O_RDWR)) < 0) {
    return -1;
  }

  rc = ioctl(fd, IOCTL_INOUT_CREDENTIALS, &cred_copy);
  close(fd);

  return rc;
}


int mira_jailbreak(void) {
  mira_thread_credentials_t cred;

  if(mira_get_credentials(&cred)) {
    return -1;
  }

  cred.caps[0] = CAPS_MAX;
  cred.caps[1] = CAPS_MAX;
  cred.caps[2] = CAPS_MAX;
  cred.caps[3] = CAPS_MAX;
  
  if(mira_set_credentials(&cred)) {
    return -1;
  }

  return 0;
}
