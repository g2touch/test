#ifndef PACKET_H
#define PACKET_H

#include <string.h>

#if defined(USE_HID_USB)
// 64bytes data composed like this.. RPT_ID[1B]/IDX[1B]/data body[62B]
#define HID_OUTPUT_MAX_LEN  (64)
#define HID_OUT_REPORT_ID   (0x80)
#else
// Total 63bytes I2C transfer..  but,, OUT_REG[2B]/LEN[2B] need to be removed..
// So.. 59bytes data composed like this.. RPT_ID[1B]/IDX[1B]/data body[57B]
#define HID_OUTPUT_MAX_LEN  (59)
#define HID_OUT_REPORT_ID   (0x0A)
#endif
#define HID_INPUT_MAX_LEN   (64)

class rxUnit
{
    public:
    	rxUnit():m_size(0),m_buf(0){ m_size = 0; m_buf = new unsigned char[HID_INPUT_MAX_LEN];}
    	~rxUnit() { if (m_buf != 0x0) delete m_buf; }

    	unsigned char* setBuf(unsigned char* buf, int size) { m_buf = new unsigned char[size]; memcpy(m_buf, buf, size); return m_buf; }
    	void clearBuf() { memset(m_buf, 0x00, HID_INPUT_MAX_LEN);}
    	int setSize(int size) { m_size = size; return m_size; }

    	int getSize() { return m_size; }
    	unsigned char* getBuf() { return m_buf; }

    private:
        rxUnit(rxUnit&); // copy constructor
        rxUnit & operator = (rxUnit&); // override
    	int m_size;
    	unsigned char* m_buf;
};


#endif // PACKET_H
