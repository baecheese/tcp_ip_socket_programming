//
//  main.c
//  EchoServer
//
//  Created by 배지영 on 27/07/2019.
//  Copyright © 2019 배지영. All rights reserved.
//

#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    // INADDR_ANY  모든 주소 허용
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(3000);
    
    // 소켓과 주소(IP + Port)를 연결
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("%s", "bind fail\n");
        return -1;
    }
    // 수신 대기열
    // back log 5개 설정 - 몇 개까지 받을 것인지
    if (listen(server_socket, 2) < 0)
    {
        printf("%s", "listen fail\n");
        return -1;
    }
    printf("%s", "listen success\n");
    
    socklen_t client_len;
    struct sockaddr_in client_addr;
    int client_socket;
    char buffer[1000];
    ssize_t read_size;
    
    while (1) {
        client_len = sizeof(client_addr);
        // server listen soket이 client socket을 accept 함수로 연결 접수
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        read_size = read(client_socket, buffer, 1000);
        printf("%s", "read success\n");
        printf("%s", buffer);
        write(client_socket, buffer, read_size);
        close(client_socket);
    }
    return 0;
}
