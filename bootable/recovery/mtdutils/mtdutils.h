

#ifndef MTDUTILS_H_
#define MTDUTILS_H_

#include <sys/types.h>  // for size_t, etc.

typedef struct MtdPartition MtdPartition;

int mtd_scan_partitions(void);

const MtdPartition *mtd_find_partition_by_name(const char *name);

int mtd_mount_partition(const MtdPartition *partition, const char *mount_point,
        const char *filesystem, int read_only);

int mtd_partition_info(const MtdPartition *partition,
        size_t *total_size, size_t *erase_size, size_t *write_size);

typedef struct MtdReadContext MtdReadContext;
typedef struct MtdWriteContext MtdWriteContext;

MtdReadContext *mtd_read_partition(const MtdPartition *);
ssize_t mtd_read_data(MtdReadContext *, char *data, size_t data_len);
ssize_t mtd_read_data_ex(MtdReadContext *ctx, char *data, size_t size, loff_t offset);
void mtd_read_close(MtdReadContext *);
void mtd_read_skip_to(const MtdReadContext *, size_t offset);

MtdWriteContext *mtd_write_partition(const MtdPartition *);
ssize_t mtd_write_data(MtdWriteContext *, const char *data, size_t data_len);
off_t mtd_erase_blocks(MtdWriteContext *, int blocks);  /* 0 ok, -1 for all */
int mtd_write_block_ex(MtdWriteContext *ctx, const char *data, off_t addr);
int mtd_write_data_ex(MtdWriteContext *ctx, const char *data, size_t size, off_t offset);
off_t mtd_find_write_start(MtdWriteContext *ctx, off_t pos);
int mtd_write_close(MtdWriteContext *);

#endif  // MTDUTILS_H_
