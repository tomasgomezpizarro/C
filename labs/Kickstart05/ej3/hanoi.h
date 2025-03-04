
#ifndef __HANOI_H__
#define __HANOI_H__

typedef struct _hanoi* hanoi_t;


hanoi_t hanoi_init(unsigned int disks_count);


void hanoi_solve(hanoi_t hanoi);


void hanoi_print(hanoi_t hanoi);


hanoi_t hanoi_destroy(hanoi_t hanoi);

#endif
