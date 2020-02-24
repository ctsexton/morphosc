#ifndef MULTITOUCH_H_
#define MULTITOUCH_H_

void scan_and_send(SenselFrameData * frame, SENSEL_HANDLE handle, int sockfd, char * oscbuffer, int total_contacts);

#endif
