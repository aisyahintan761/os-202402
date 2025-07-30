// vm.h

#ifndef VM_H
#define VM_H

#include "param.h"
#include "mmu.h"
#include "memlayout.h"

void            seginit(void);
void            kvmalloc(void);
void            vmenable(void);
pde_t*          setupkvm(void);
char*           kalloc(void);
void            kfree(char*);
int             mappages(pde_t*, void*, uint, uint, int);
pde_t*          copyuvm(pde_t*, uint);
pde_t*          cowuvm(pde_t*, uint);      // ✅ Tambahkan ini
pte_t* walkpgdir(pde_t *pgdir, const void *va, int alloc);
void            switchuvm(struct proc*);
void            switchkvm(void);
int             deallocuvm(pde_t*, uint, uint);
int             allocuvm(pde_t*, uint, uint);
void            freevm(pde_t*);
void            inituvm(pde_t*, char*, uint);
int             loaduvm(pde_t*, char*, struct inode*, uint, uint);
int             copyout(pde_t*, uint, void*, uint);
void            clearpteu(pde_t *pgdir, char *uva);

// Tambahan untuk Copy-On-Write
void            inc_ref(uint pa);          // ✅ Tambahkan deklarasi
void            dec_ref(uint pa);
int             get_ref(uint pa);


#endif // VM_H
