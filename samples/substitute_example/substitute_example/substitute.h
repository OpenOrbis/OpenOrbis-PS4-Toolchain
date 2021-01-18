#pragma once

#ifndef SUBSTITUTE_H
#define SUBSTITUTE_H

#define MIRA_IOCTL_IAT_HOOK    0xC2185301
#define MIRA_IOCTL_JMP_HOOK    0xC0185302
#define MIRA_IOCTL_STATE_HOOK  0xC0185303

#define SUBSTITUTE_MAX_NAME 255 // Max lenght for name
#define SUBSTITUTE_MAIN_MODULE "" // Define the main module

enum {
  SUBSTITUTE_IAT_NAME = 0,
  SUBSTITUTE_IAT_NIDS = 1
};

enum {
  SUBSTITUTE_STATE_DISABLE = 0,
  SUBSTITUTE_STATE_ENABLE = 1,
  SUBSTITUTE_STATE_UNHOOK = 2
};

// IOCTL IN/OUT Structure
struct substitute_state_hook {
  int hook_id;
  int state;
  struct substitute_hook* chain;
  int result;
};

struct substitute_hook_iat {
  int hook_id;
  char name[SUBSTITUTE_MAX_NAME];
  char module_name[SUBSTITUTE_MAX_NAME];
  int flags;
  void* hook_function;
  struct substitute_hook* chain;
};

// Structure for userland
struct substitute_hook {
  int hook_id;
  void* hook_function;
  void* original_function;
  void* next;
};

// Thanks Yifan ! (taiHEN source code)
// Chain execution (All chain edition was do by kernel)

#define SUBSTITUTE_WAIT(hook) while (!hook) {}

#define SUBSTITUTE_CONTINUE(type, hook, argl, ...) ({ \
  struct substitute_hook *cur, *next; \
  cur = (struct substitute_hook *)(hook); \
  next = (struct substitute_hook *)cur->next; \
  (next == NULL) ? \
    ((type(*)argl)cur->original_function)(__VA_ARGS__) \
  : \
    ((type(*)argl)next->hook_function)(__VA_ARGS__) \
  ; \
})


struct substitute_hook* substitute_hook(const char* module_name, const char* name, void* hook_function, int flags);
int substitute_statehook(struct substitute_hook* hook, int state);
int substitute_disable(struct substitute_hook* hook);
int substitute_enable(struct substitute_hook* hook);
int substitute_unhook(struct substitute_hook* hook);

#endif
