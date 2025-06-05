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
        cout << "�۸�" << endl;
    }
};

class Cat : public Animal 
{
    void makeSound() const override 
    {
        cout << "�߿�" << endl;
    }
};

class Cow :public Animal 
{
    void makeSound() const override 
    {
        cout << "����" << endl;
    }
};

class Zoo 
{
private :
    Animal* animals[10];    // ���� ��ü�� �����ϴ� ������ �迭
    int count = 0;

public:
    // ������ �������� �߰��ϴ� �Լ�
    void addAnimal(Animal* animal) 
    {
        if (count < 10)
        {
            // - Animal ��ü�� �����͸� �޾� ������ �迭�� �����մϴ�.
            animals[count++] = animal;
        }
        else
        {
            cout << "�� �̻� ������ �߰��� �� �����ϴ�." << endl;
        }
    };

    // �������� �ִ� ��� ������ �ൿ�� �����ϴ� �Լ�
    void performActions() 
    {
        // - ��� ���� ��ü�� ���� ���������� �Ҹ��� ���� �����̴� ������ �����մϴ�.
        for (int i = 0; i < count; ++i)
        {
            animals[i]->makeSound();
        }
    };

    // Zoo �Ҹ���
    ~Zoo() 
    {
        // - Zoo ��ü�� �Ҹ�� ��, ���� ���Ϳ� ����� ��� ���� ��ü�� �޸𸮸� �����մϴ�.
        for (int i = 0; i < count; ++i)
        {
            // - �޸� ������ �����ϱ� ���� ���� �Ҵ�� Animal ��ü�� `delete` �մϴ�.
            delete animals[i];
        }
    };
};

// ���� ������ �����ϴ� �Լ�
Animal* createRandomAnimal() 
{
    // - 0, 1, 2 �� �ϳ��� ������ �����Ͽ� ���� Dog, Cat, Cow ��ü �� �ϳ��� �������� �����մϴ�.
    int r = rand() % 3;

    // - ������ ��ü�� Animal Ÿ���� �����ͷ� ��ȯ�˴ϴ�.
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
    // ���� �ʱ�ȭ
    srand(time(0));

    Zoo zoo;

    // ������ ���� 5���� �߰�
    for (int i = 0; i < 5; ++i)
    {
        zoo.addAnimal(createRandomAnimal());
    }

    // ��� ���� �ൿ ����
    zoo.performActions();
}
