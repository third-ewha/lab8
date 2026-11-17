#include "bookPtr.h"
#include <utility>

#include "bookPtr.h"
#include <iostream>
#include <memory>
#include <utility>

int main()
{
    using namespace leedahae2449069;

    // 원하는 값으로 bookPtr 객체1 생성, 출력
    bookPtr bp1{book{1, 10000}};
    bp1.print();

    // 객체1의 값으로 bookPtr 객체2 생성, 출력
    bookPtr bp2{bp1};
    bp2.print();

    // 객체2를 이동시켜 bookPtr 객체3 생성, 객체2와 객체3 출력
    bookPtr bp3{std::move(bp2)};
    bp2.print();
    bp3.print();

    // 객체2에 객체3을 이동시켜 할당
    bp2 = std::move(bp3);

    // 객체3에 객체2를 복사할당
    bp3 = bp2;

    // bookPtr을 가리키는 unique_ptr 객체1 선언
    std::unique_ptr<bookPtr> up1;

    // bookPtr을 가리키는 unique_ptr 객체2를 원하는 값으로 초기화
    auto up2 = std::make_unique<bookPtr>(book{2, 20000});

    // unique_ptr 객체1에 객체2를 이동, 가리키는 값 출력
    up1 = std::move(up2);
    up1->print();

    // bookPtr을 가리키는 shared_ptr 객체1을 원하는 값으로 초기화
    auto sp1 = std::make_shared<bookPtr>(book{3, 30000});

    // shared_ptr 객체2를 객체1로 초기화
    std::shared_ptr<bookPtr> sp2{sp1};

    // shared_ptr 객체1의 use_count 출력
    std::cout << sp1.use_count() << '\n';

    // shared_ptr 객체2의 use_count 출력
    std::cout << sp2.use_count() << '\n';

    // weak_ptr 객체1을 shared_ptr 객체1로 초기화
    std::weak_ptr<bookPtr> wp1{sp1};

    // shared_ptr 객체1의 use_count 출력
    std::cout << sp1.use_count() << '\n';

    // shared_ptr 객체2의 use_count 출력
    std::cout << sp2.use_count() << '\n';

    // shared_ptr 객체1에서 reset 호출
    sp1.reset();

    // shared_ptr 객체1의 use_count 출력
    std::cout << sp1.use_count() << '\n';

    // shared_ptr 객체2의 use_count 출력
    std::cout << sp2.use_count() << '\n';

    // weak_ptr 객체1이 expired 상태가 아니면
    if (!wp1.expired())
    {
        // lock의 반환값을 shared_ptr 객체1에 할당
        sp1 = wp1.lock();
    }

    // shared_ptr 객체1의 use_count 출력
    std::cout << sp1.use_count() << '\n';

    // shared_ptr 객체2의 use_count 출력
    std::cout << sp2.use_count() << '\n';

    return 0;
}

// 4. main.cpp: 테스트

// 원하는 값으로 클래스1Ptr형 객체1 생성, 출력

// 클래스1Ptr형 객체1 값으로 클래스1Ptr형 객체2 생성, 출력 

// 클래스1Ptr형 객체2를 이동시켜 클래스1Ptr형 객체3 생성, 객체2와 객체3 출력

// 클래스1Ptr형 객체2에 클래스1Ptr형 객체3을 이동시켜 할당

// 클래스1Ptr형 객체3에 객체2를 복사할당



// 클래스1Ptr형을 가리키는 unique_ptr 객체1을 선언

// 클래스1Ptr형을 가리키는 unique_ptr 객체2를 선언하면서 원하는 값으로 초기화 (make_unique 사용)

// unique_ptr 객체1에 unique_ptr 객체2를 이동, unique_ptr 객체1이 가리키는 값을 출력



// 클래스1Ptr형을 가리키는 shared_ptr 객체1을 선언하면서, 원하는 값으로 초기화

// 클래스1Ptr형을 가리키는 shared_ptr 객체2를 선언하면서 shared_ptr 객체1로 초기화

// shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

// shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

// 클래스1Ptr형을 가리키는 weak_ptr 객체1을 선언하면서 shared_ptr 객체1로 초기화

// shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

// shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

// shared_ptr 객체1에서 reset 멤버함수를 호출한 후

// shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

// shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

// weak_ptr 객체1에서 expired 멤버함수를 호출하여 expired가 아니면 (메모리가 있으면)

// weak_ptr 객체1에서 lock 멤버함수를 호출한 값을 shared_ptr 객체1에 할당 후 

// shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

// shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력
