#ifndef _XBOOK_SRVCALL_H
#define _XBOOK_SRVCALL_H

#include <sys/srvcall.h>

/* 服务调用 service call */
void init_srvcall();


#define SRVCALL_LISTEN      1
#define SRVCALL_PENDING     2
#define SRVCALL_ACK         3
#define SRVCALL_FINISH      4

#define SRVCALL_NR  3
#define IS_BAD_SRVCALL(port) \
        ((port) < 0 || port >= SRVCALL_NR)


#define COPY_SRVMSG(dst, src) \
        memcpy((dst), (src), sizeof(srvcall_arg_t));

int sys_srvcall_bind(int port);
int sys_srvcall_unbind(int port);
int sys_srvcall_listen(int port, srvcall_arg_t *arg);
int sys_srvcall_ack(int port, srvcall_arg_t *arg);
int sys_srvcall(int port, srvcall_arg_t *arg);

#endif   /* _XBOOK_SRVCALL_H */
