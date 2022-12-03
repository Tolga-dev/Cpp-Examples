#include <pcap/pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include<netinet/if_ether.h>
#include<netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    char *device; /* Name of device (e.g. eth0, wlan0) */
    char error_buffer[PCAP_ERRBUF_SIZE]; /* Size defined in pcap.h */

    printf("Device: %s\n", device);
    return 0;
}
