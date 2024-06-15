# 실행부 설명
### 빌트인 함수 구현
1. cd
2. env
3. pwd
4. exit
5. export
6. unset
7. echo
### 그 외 명령어 실행
1. execvp

### 구조체 받을 때 규칙
1. env 를 인자로 넘겨줄 때 key는 NULL이 아님을 보증해야함
2. 명령어 중에서 파싱해야 할 것들은 파싱을 한 후에 넘겨줘야함
    - $PWD => local/bin 으로 바꿔서 넘겨줘야함