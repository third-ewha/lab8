#pragma once
#include "book.h"
#include <iostream>

namespace leedahae2449069
{
    class bookPtr
    {
        book* bPtr;

    public:
        bookPtr(const book& b = book{1, 10000})
            : bPtr{new book{b}}
        {
            std::cout << "constructor\n";
        }
        void print() const
{
    if (bPtr)
        std::cout << *bPtr;
    else
        std::cout << "no data (nullptr)\n";
}

        ~bookPtr()
        {
            std::cout << "~destructor\n";
            delete bPtr;
        }

        bookPtr(const bookPtr& copy)
            : bPtr{copy.bPtr ? new book{*copy.bPtr} : nullptr}
        {
            std::cout << "copy constructor\n";
        }

        bookPtr(bookPtr&& move) noexcept
            : bPtr{move.bPtr}
        {
            move.bPtr = nullptr;
            std::cout << "move constructor\n";
        }

        bookPtr& operator=(const bookPtr& copy)
        {
            std::cout << "copy operator=\n";
            if (this != &copy)
            {
                book* newPtr = copy.bPtr ? new book{*copy.bPtr} : nullptr;
                delete bPtr;
                bPtr = newPtr;
            }
            return *this;
        }

        bookPtr& operator=(bookPtr&& move) noexcept
        {
            std::cout << "move operator=\n";
            if (this != &move)
            {
                delete bPtr;
                bPtr = move.bPtr;
                move.bPtr = nullptr;
            }
            return *this;
        }
    };
}

// //3. 클래스1Ptr.h: 클래스1Ptr 클래스 정의

// 1의 본인이름학번의 네임스페이스 안에 클래스를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 

// private 멤버변수 선언: 클래스1형을 가리키는 포인터

// public 멤버함수 정의

// -생성자, 소멸자, 복사생성자, 복사=연산자, 이동생성자, 이동=연산자

// -print: 멤버변수가 가리키는 데이터가 있을 경우 표준스트림으로 출력, 없으면 no data (nullptr) 출력

