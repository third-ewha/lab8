#include "bookPtr.h"
#include <utility>

int main()
{
    using namespace leedahae2449069;

    bookPtr bp1;
    bookPtr bp2{bp1};             // copy constructor
    bookPtr bp3{std::move(bp2)};  // move constructor
    // bp3 = bp1;

    return 0;
}



4. main.cpp: 테스트

원하는 값으로 클래스1Ptr형 객체1 생성, 출력

클래스1Ptr형 객체1 값으로 클래스1Ptr형 객체2 생성, 출력 

클래스1Ptr형 객체2를 이동시켜 클래스1Ptr형 객체3 생성, 객체2와 객체3 출력

클래스1Ptr형 객체2에 클래스1Ptr형 객체3을 이동시켜 할당

클래스1Ptr형 객체3에 객체2를 복사할당



클래스1Ptr형을 가리키는 unique_ptr 객체1을 선언

클래스1Ptr형을 가리키는 unique_ptr 객체2를 선언하면서 원하는 값으로 초기화 (make_unique 사용)

unique_ptr 객체1에 unique_ptr 객체2를 이동, unique_ptr 객체1이 가리키는 값을 출력



클래스1Ptr형을 가리키는 shared_ptr 객체1을 선언하면서, 원하는 값으로 초기화

클래스1Ptr형을 가리키는 shared_ptr 객체2를 선언하면서 shared_ptr 객체1로 초기화

shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

클래스1Ptr형을 가리키는 weak_ptr 객체1을 선언하면서 shared_ptr 객체1로 초기화

shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

shared_ptr 객체1에서 reset 멤버함수를 호출한 후

shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

weak_ptr 객체1에서 expired 멤버함수를 호출하여 expired가 아니면 (메모리가 있으면)

weak_ptr 객체1에서 lock 멤버함수를 호출한 값을 shared_ptr 객체1에 할당 후 

shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력
