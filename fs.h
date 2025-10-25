#ifndef FS_H
#define FS_H

#include <time.h>

#define MAX_FILES 64
#define MAX_FILENAME 32
#define BLOCK_SIZE 1024
#define METADATA_SIZE sizeof(Metadata)

typedef struct {
    char name[MAX_FILENAME];
    int size;
    time_t created_at;
    int is_used;
    int start_block;
} FileEntry;

typedef struct {
    int file_count;
    FileEntry files[MAX_FILES];
} Metadata;

// Dosya sistemi işlemleri
void fs_format();
void fs_create(const char* filename);
void fs_ls();
void fs_write(const char* filename, const char* data, int size);
void fs_read(const char* filename, int offset, int size, char* buffer);
void fs_delete(const char* filename);
int  fs_exists(const char* filename);
void fs_append(const char* filename, const char* data, int size);
void fs_truncate(const char* filename, int new_size);
void fs_copy(const char* src, const char* dest);
void fs_cat(const char* filename);
void fs_backup(const char* backup_filename);
void fs_restore(const char* backup_filename);
void fs_diff(const char* f1, const char* f2);
void fs_log();
void fs_mv(const char* oldname, const char* newname);
void fs_size(const char* filename);
void fs_check_integrity();
void fs_defragment();
void append_to_log(const char* message);

#endif // FS_H

