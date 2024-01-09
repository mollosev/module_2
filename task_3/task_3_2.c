#include "task_3.h"

int main(int argc, char * argv[]) {
    srand(time(NULL));
    unsigned int mask = convert(argv[2]);
    unsigned int ip_src = convert(argv[1]);
    unsigned int net_src = ip_src & mask;
    int numbers_of_packets = atoi(argv[3]);
    unsigned int our_net = 0;
    unsigned int ip_dst;
    unsigned int net_dst;
    for(int n=0; n<numbers_of_packets; n++) {
        ip_dst = rand()+rand();
        net_dst = ip_dst & mask;
        if (!(net_dst ^ net_src)) our_net++;
    }
    printf("Packets for our subnet: %d pcs %.8f%%\n", our_net, (double)our_net*100/numbers_of_packets);
    printf("Packets for other subnets: %d pcs %.8f%%\n", numbers_of_packets-our_net, (double)(numbers_of_packets-our_net)*100/numbers_of_packets);
}

unsigned int convert(char *ip_str) {
    unsigned int ip_src = 0;
    char * oct[4];
    int len = strlen(ip_str);
    oct[0]=ip_str;
    int num_of_oct = 1;
    int index_of_char=0;
    while(num_of_oct<4) {
        if (ip_str[index_of_char] == '.') {
            ip_str[index_of_char] = '\0';
            oct[num_of_oct]= &ip_str[index_of_char+1];
            num_of_oct++;
        }
        index_of_char++;
    }
    for(int i=0; i<4; i++) {
        ip_src |= atoi(oct[i]) << 32-(i+1)*8;
    }
    return ip_src;
}