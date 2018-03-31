/*********************************************************
 * Copyright (C) 2015 All rights reserved.
 * Author        : Ewen Dong
 * Email         : ewen.dong@cloudminds.com
 * Filename      : CommonBuffer.h
 * Last modified : 2015-08-25
 * Description   :
 *********************************************************/

#ifndef _COMMONBUFFER_H_
#define _COMMONBUFFER_H_

#include <cstring>

class CCommonBuffer {
public:
    CCommonBuffer() {
        m_pbuffer = NULL;
        m_nalloc_size = 0;
        m_nwrite_offset = 0;
    }
    ~CCommonBuffer() {
        m_nalloc_size = 0;
        m_nwrite_offset = 0;
        if (m_pbuffer) {
            free(m_pbuffer);
            m_pbuffer = NULL;
        }
    }
    char* GetBuffer() {
        return m_pbuffer;
    }
    const char* GetBuffer() const {
        return m_pbuffer;
    }
    int GetAllocSize() {
        return m_nalloc_size;
    }
    int GetWriteOffset() {
        return m_nwrite_offset;
    }
    void IncWriteOffset(int nlen) {
        m_nwrite_offset += nlen;
    }

    void Extend(int nlen) {
        m_nalloc_size = m_nwrite_offset + nlen;
        m_nalloc_size += m_nalloc_size >> 2;    // increase by 1/4 allocate size
        char* new_buf = (char*) realloc(m_pbuffer, m_nalloc_size);
        if (new_buf != NULL) {
            m_pbuffer = new_buf;
        }
    }

    int Write(const char* pbuf, int nlen) {
        if (m_nwrite_offset + nlen > m_nalloc_size) {
            Extend(nlen);
        }

        if (pbuf) {
            memcpy(m_pbuffer + m_nwrite_offset, pbuf, nlen);
        }

        m_nwrite_offset += nlen;

        return nlen;
    }

    int Read(char* pbuf, int nlen) {
        if (nlen > m_nwrite_offset)
            nlen = m_nwrite_offset;

        if (pbuf)
            memcpy(pbuf, m_pbuffer, nlen);

        m_nwrite_offset -= nlen;
        memmove(m_pbuffer, m_pbuffer + nlen, m_nwrite_offset);
        return nlen;
    }
private:
    char* m_pbuffer;
    int m_nalloc_size;
    int m_nwrite_offset;
};

#endif
