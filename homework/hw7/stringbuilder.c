#include<stdlib.h>
#include"stringbuilder.h"

static void sb_grow(struct string_builder *sb){
    int new_capacity=sb->capacity*2;
    char *new_buf=malloc(new_capacity *sizeof(char));
    
    if(new_buf==NULL){
        return;
    }
         
    for(int j=0;j<sb->size;j++){
        new_buf[j]=sb->buf[j];
    }

    free(sb->buf);
    sb->buf=new_buf;
    sb->capacity=new_capacity;

}

struct string_builder sb_init(int capacity){
    struct string_builder sb;
    sb.capacity=capacity;
    sb.size=0;

    sb.buf=malloc(capacity*sizeof(char));

    return sb;
}

void sb_appendn(struct string_builder *sb,  char const *buf, int len){
    int i=0;
    while(i<len&&buf[i]!='\0'){
        if(sb->size==sb->capacity){
            sb_grow(sb);
        }
        sb->buf[sb->size]=buf[i];
        sb->size++;
        i++;
    }
}

void sb_append(struct string_builder *sb, char const *buf){
    int len=0;
    while(buf[len]!='\0'){
        len++;
    }

    sb_appendn(sb, buf, len);
}

void sb_copy_to(struct string_builder const *sb, char *dst, int len){
    if(len<=0){
        return;
    }

    int copy_len=sb->size;

    if(copy_len>len-1){
        copy_len=len-1;
    }

    for(int i=0;i<copy_len;i++){
        dst[i]=sb->buf[i];
    }
    dst[copy_len]='\0';


}

char *sb_build(struct string_builder const *sb){
    char *result = malloc((sb->size+1)*sizeof(char));

    if(result==NULL){
        return NULL;
    }

    sb_copy_to(sb, result, sb->size+1);

    return result;
}

void sb_destroy(struct string_builder *sb){
    free(sb->buf);
    sb->buf=NULL;
    sb->size=0;
    sb->capacity=0;
}
