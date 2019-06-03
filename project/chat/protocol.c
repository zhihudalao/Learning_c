#include "protocol.h"

PDU *mkPDU()
{
	PDU *pdu = (PDU *)malloc(sizeof(PDU));
	memset(pdu, 0, sizeof(PDU));

	return pdu;
}
