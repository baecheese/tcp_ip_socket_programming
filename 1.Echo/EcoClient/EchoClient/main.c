//
//  main.c
//  EchoClient
//
//  Created by 배지영 on 27/07/2019.
//  Copyright © 2019 배지영. All rights reserved.
//

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, const char * argv[]) {
    // 소켓 생성 및 설정
    int sockfd;
    // AF_INET  IPv4인터넷 프로토콜
    // SOCK_STREAM : TCP 프롤토콜의 전송 방식
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    // 소켓 주소 생성 및 설정
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(3000);
    
    // 연결
    int connect_code = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if (connect_code < 0) {
        printf("connect error %d", connect_code);
        return 1;
    }
    
    // buffer 생성
    char buffer[1000];
    // 입력 받음
    size_t readn;
    readn = read(0, buffer, 1000);
    // 입력 받은 정보를 서버에 씀
    write(sockfd, buffer, readn);
    
    // 메모리에 연속된 범위로 값을 지정
    memset(buffer, 0x000, 1000);
    // 서버로 부터 데이터를 읽어옴
    read(sockfd, buffer, 1000-1);
    printf("server %s", buffer);
    // 종료
    close(sockfd);
    return 0;
}
