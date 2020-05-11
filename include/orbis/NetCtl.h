#ifndef _SCE_NET_CTL_H_
#define _SCE_NET_CTL_H_

#include <sys/stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

#define ORBIS_NET_CTL_INFO_DEVICE			1
#define ORBIS_NET_CTL_INFO_ETHER_ADDR		2
#define ORBIS_NET_CTL_INFO_MTU			3
#define ORBIS_NET_CTL_INFO_LINK			4
#define ORBIS_NET_CTL_INFO_BSSID			5
#define ORBIS_NET_CTL_INFO_SSID			6
#define ORBIS_NET_CTL_INFO_WIFI_SECURITY		7
#define ORBIS_NET_CTL_INFO_RSSI_DBM		8
#define ORBIS_NET_CTL_INFO_RSSI_PERCENTAGE	9
#define ORBIS_NET_CTL_INFO_CHANNEL		10
#define ORBIS_NET_CTL_INFO_IP_CONFIG		11
#define ORBIS_NET_CTL_INFO_DHCP_HOSTNAME		12
#define ORBIS_NET_CTL_INFO_PPPOE_AUTH_NAME	13
#define ORBIS_NET_CTL_INFO_IP_ADDRESS		14
#define ORBIS_NET_CTL_INFO_NETMASK		15
#define ORBIS_NET_CTL_INFO_DEFAULT_ROUTE		16
#define ORBIS_NET_CTL_INFO_PRIMARY_DNS		17
#define ORBIS_NET_CTL_INFO_SECONDARY_DNS		18
#define ORBIS_NET_CTL_INFO_HTTP_PROXY_CONFIG	19
#define ORBIS_NET_CTL_INFO_HTTP_PROXY_SERVER	20
#define ORBIS_NET_CTL_INFO_HTTP_PROXY_PORT	21
#define ORBIS_NET_CTL_INFO_RESERVED1		22
#define ORBIS_NET_CTL_INFO_RESERVED2		23

typedef union OrbisNetCtlInfo {
	uint32_t device;
	char ether_addr[6];
	uint32_t mtu;
	uint32_t link;
	char bssid[6];
	char ssid[33];
	uint32_t wifi_security;
	uint8_t rssi_dbm;
	uint8_t rssi_percentage;
	uint8_t channel;
	uint32_t ip_config;
	char dhcp_hostname[256];
	char pppoe_auth_name[128];
	char ip_address[16];
	char netmask[16];
	char default_route[16];
	char primary_dns[16];
	char secondary_dns[16];
	uint32_t http_proxy_config;
	char http_proxy_server[256];
	uint16_t http_proxy_port;
} OrbisNetCtlInfo;

void sceNetCtlGetInfo(int, void *);
void sceNetCtlInit();

#endif

#ifdef __cplusplus
}
#endif
