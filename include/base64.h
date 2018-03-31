#ifndef _H_BASE64_H_
#define _H_BASE64_H_

#ifdef __cplusplus
extern "C" {
#endif

char* base64_encode(const unsigned char *data,int dlen);
int base64_decode(const char *bdata,unsigned char** out_data);

#ifdef __cplusplus
}
#endif


#endif


