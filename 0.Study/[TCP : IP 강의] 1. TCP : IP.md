# [TCP / IP 강의] 1. TCP / IP
## IP
* 분산 네트워크 구조를 유지하기 위한 프로토콜
* 네트워크의 구성 : 링크 / 노드
	* 각 노드는 원하는 노드 들을 찾을 수 있는 경로가 있어야함 = IP
* 노드와 노드 사이에는 경로설정을 위해 라우터가 배치된다.

## TCP
* 패킷데이터 전송 방식
* TCP = 패킷의 흐름을 제어하기 위함 프로토콜
	* 여러 조각으로 쪼개진 패킷은 여러 상태로 전송된다 (훼손, 지연 등)
	* TCP는 패킷을 재조립하고, 재전송을 요청하는 등의 흐름을 관리

## OSI 7계층
![](%5BTCP%20:%20IP%20%E1%84%80%E1%85%A1%E1%86%BC%E1%84%8B%E1%85%B4%5D%201.%20TCP%20:%20IP/213F623C566BAE253B.png)

* 네트워크 프로그래밍 : 주요한 프로토콜의 규약은 소켓 라이브러리가 함수를 이용한 과정

## TCP/IP 4 Layer와 데이터 통신
![](%5BTCP%20:%20IP%20%E1%84%80%E1%85%A1%E1%86%BC%E1%84%8B%E1%85%B4%5D%201.%20TCP%20:%20IP/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202019-07-21%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%204.25.09.png)

### 1. HTTP protocol -> TCP Protocol -> IP Protocol -> Enternet Protocol 을 거치며 데이터 통신 (multiplexing)
	* Multiplexing 알고리즘 : SELECT, EPOLL, IOCP…
	* 데이터든 각 단계를 거치면서 프로토콜을 선택 / 해당 정보를 캡슐레이션 한다
	- [ ] HTTP protocol -> TCP Protocol -> IP Protocol -> Enternet Protocol
	- [ ] user data -> user data + TCP Header -> user data + TCP Header + IP Protocol -> user data + TCP Header + IP Protocol + Enternet Protocol

### 2. 라우터
* 1의 과정을 거쳐 이터넷으로 나간 데이터는 **Router**에 의해 경로가 설정된다.

### 3. 목적지에 도착 후 디멀티플래싱(Demultiplexing)
* 1의 반대의 과정을 거쳐 웹서버에 도착


#Development/study