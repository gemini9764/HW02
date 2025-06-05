#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal 
{
public:
    virtual void makeSound() const = 0;
    virtual ~Animal() {};
};

class Dog : public Animal 
{
public:
    void makeSound() const override 
    {
        cout << "멍멍" << endl;
    }
};

class Cat : public Animal 
{
    void makeSound() const override 
    {
        cout << "야옹" << endl;
    }
};

class Cow :public Animal 
{
    void makeSound() const override 
    {
        cout << "음머" << endl;
    }
};

class Zoo 
{
private :
    Animal* animals[10];    // 동물 객체를 저장하는 포인터 배열
    int count = 0;

public:
    // 동물을 동물원에 추가하는 함수
    void addAnimal(Animal* animal) 
    {
        if (count < 10)
        {
            // - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
            animals[count++] = animal;
        }
        else
        {
            cout << "더 이상 동물을 추가할 수 없습니다." << endl;
        }
    };

    // 동물원에 있는 모든 동물의 행동을 수행하는 함수
    void performActions() 
    {
        // - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
        for (int i = 0; i < count; ++i)
        {
            animals[i]->makeSound();
        }
    };

    // Zoo 소멸자
    ~Zoo() 
    {
        // - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
        for (int i = 0; i < count; ++i)
        {
            // - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
            delete animals[i];
        }
    };
};

// 랜덤 동물을 생성하는 함수
Animal* createRandomAnimal() 
{
    // - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
    int r = rand() % 3;

    // - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
    switch (r)
    {
    case 0:
        return new Dog();
    case 1:
        return new Cat();
    case 2:
        return new Cow();
    default:
        return nullptr;
    }
};

int main()
{
    // 난수 초기화
    srand(time(0));

    Zoo zoo;

    // 랜덤한 동물 5마리 추가
    for (int i = 0; i < 5; ++i)
    {
        zoo.addAnimal(createRandomAnimal());
    }

    // 모든 동물 행동 수행
    zoo.performActions();
}
