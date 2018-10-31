//
//  main.cpp
//  day05
//
//  Created by yhp on 2018/10/28.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>

using namespace std;

struct POINT {
    int x;
    int y;
};

class Pos {
public:
    Pos(int x = 0,int y = 0){
        p_.x = x;
        p_.y = y;
    }
    void move(int cx,int cy){
        p_.x += cx;
        p_.y += cy;
    }
    void moveto(int x,int y){
        p_.x = x;
        p_.y = y;
    }
    
    POINT* operator ->() {
        return &p_;
    }
private:
    POINT p_;
};

class A {
public:
    A(int d=0):data_(d){
        cout << "A(" << data_ <<")" << endl;
    }
    ~A(){
        cout << "~A(" << data_ <<")" << endl;
    }
    void* operator new(size_t bytes){
        cout << "bytes=" << bytes << endl;
       return malloc(bytes);
    }
    //  编译器会藏匿几个字节来存储数组大小的值
    //  MAC OS 为 8个字节
    void* operator new[](size_t bytes){
        cout << "BYTES=" << bytes << endl;
        void* p = malloc(bytes);
        cout << "P=" << p << endl;
        return p;
    }
    void operator delete(void* p){
        assert(p != NULL);
        cout << "free " << p << endl;
        free(p);
    }

    void operator delete[](void* p){
        assert(p != NULL);
        cout << "FREE " << p << endl;
        free(p);
    }
        
private:
    int data_;
};

class R {
public:
    friend ostream& operator << (ostream& o,const R& x){
        o << x.n_ << "/" << x.d_;
        return o;
    }
    
    R(int n=0,int d=1):n_(n),d_(d){
        
    }
//   operator++(a) a.operator++()
    R& operator++(){
        n_ += d_;
        return *this;
    }
//  后++ 指定一个虚假的int类型的形参，用于区分前++还是后++
    R operator++(int){
        R old = *this;
        n_ += d_;
        return old;
    }
    
//  友元实现 --
    friend R&operator--(R& x){
        // 不是成员函数b没有当前对象 无法访问this,是哑元
        x.n_ -= x.d_;
        return x;
    }
private:
    int n_;
    int d_;
};
        
class Person{
public:
    Person(const char* n):name_(n){
        cout << "Person(" << n << ")" << endl;
    }
    ~Person(){
        cout << "Person()" << endl;
    }
    void show(){
        cout << "show:" << name_ << endl;
    }
    void setname(const char* n){
        name_ = n;
    }
    void eat(string food){
        cout << name_ << " eat " << food << endl;
    }
    void speak(string words){
       cout <<"111---"<< name_ << " say " << words << endl;
    }
    const string& getName() {
        return name_;
    }
//  允许在子类中访问，不允许在别的地方访问
protected:
    string name_;
};

class Teacher : public Person{
private:
    string course_;
public:
//    如果要向父类构造传递参数，需要在初始化列表中用父类类名来标识
    Teacher(const char* n,const char* c):course_(c),Person(n){
        cout << "Teacher() " << n << "," << c << endl;
    }
    ~Teacher(){
        cout << "~Teacher()" << endl;
    }
    void teach(string someclass){
       cout << name_ << " teach " << someclass << "," << course_ << endl;
    }
    void setcourse(string c){
        course_ = c;
    }
    void show(){
        cout << "222---" << name_ << " teach" << course_ << endl;
    }
};
        
// 多重继承
class Phone{
public:
    Phone(){
        cout << "Phone()" << endl;
    }
    void call(string num){
        cout << "打电话给" << num << endl;
    }
};

class Camera{
public:
    Camera(){
        cout << "Camera()" << endl;
    }
    void takephoto(string target){
        cout << "照了一张" << target << endl;
    }
};
        
class CellPhone:public Phone,public Camera{
public:
    /* 构造函数按照继承顺序一次调用父类构造器
        析构函数正好相反
     */
    CellPhone():Camera(),Phone(){ // 零初始化，排名不分先后
        cout << "CellPhone()" << endl;
    }
};
        
// 虚继承
class Person2{
public:
    Person2(const char* n):name_(n){
        cout << "Person2 " << n << endl;
    }
    const string& Name() const{
        return name_;
    }
private:
    string name_;
};
// 虚继承：如果希望某一个类被继承到某一级子类中时有了
// 多份要合并保留一份，这个类在继承时应该用virtual声明
// 为虚继承，这个类就是虚基类
// 虚继承中虚基类的构造函数由最底下合并的那个子类的构造
// 函数之间传递参数
class Teacher2 :virtual public Person2{
public:
    Teacher2(const char* n,const char* c):course_(c),Person2(n){
        cout << "Teacher() " << n << "," << c << endl;
    }
    void teach(string someclass){
        cout << Name() << " teach " << someclass << "," << course_ << endl;
    }
private:
    string course_;
};

class Student:virtual public Person2{
public:
    Student(const char* n,const char* s)
    :sid_(s),Person2(n){
        cout << "Student(" << n << "," << s << endl;
    }
    void listen(const char* room){
        cout << Name() << "在" << room << "听课" << endl;
    }
private:
    string sid_;
};

class DoubleMan:public Student,public Teacher2{
public:
    DoubleMan(const char* n,const char* c,
      const char* id):Teacher2(n,c),Student(n,id),Person2(n){
        cout << "DoubleMan " << endl;
    }
};
        
// 多态
// 虚函数表: 编译器把这个类的全部虚函数的地址都存在一张表中
// 每个这类对象里会藏一个指针指向这个虚函数表(在构造函数里做的)
// 对象长度增加4（mac os是8）个字节

/*
利用多态实现类型识别
dynamic_cast<子类类型&>(是父类类型对象) ---
一般用这个结果来初始化一个子类类型的对象的引用或者当场使用。成功
则一切顺利，失败会抛出l异常,终止程序
dynamic_cast<子类*>(是父类类型对象地址) ---成功
则一切顺利，失败则结果为NULL，常常使用这一种
dynamic_cast 要求有虚函数。
*/
class Vehicle{
public:
//  如果希望在调用函数时系统根据对象的真实类型
//  调用响应的函数，需要把这个函数声明成虚函数
//  子类中可以覆盖这个函数这个函数自动成为虚函数
//  覆盖[override],函数名和参数表都相同,返回类型也要一致
//  父类中返回父类指针,子类中可以返回子类指针
    virtual void stop(){
        cout << "交通工具停止" << endl;
    }// 虚函数
};
        
class Car:public Vehicle{
public:
    void stop(){
        cout << "汽车停止" << endl;
    }
};
        
class Bike:public Vehicle{
public:
    void stop(){
        cout << "自行车停止" << endl;
    }
};

class Light{
public:
    void stopvehicle(Vehicle& v){
        v.stop();
    }
};

class Animal{
public:
    virtual void eat(){
        cout << "动物吃食物" << endl;
    }
    virtual void shout(){
        cout << "动物叫" << endl;
    }
private:
    string name_;
    char   gender_;// 补齐
};

class Cat:public Animal{
    void eat(){
        cout << "猫吃猫娘" << endl;
    }
    void shout(){
        cout << "猫叫" << endl;
    }
};
        
class Dog:public Animal{
    void eat(){
        cout << "狗吃大便" << endl;
    }
    void shout(){
        cout << "狗叫" << endl;
    }
};

class Jiafei:public Cat {
    void eat(){
        cout << "加菲吃面" << endl;
    }
    void shout(){
        cout << "加菲叫" << endl;
    }
};

class Person3{
public:
    void play(Animal& a){
        a.eat();
        a.shout();
    }
};

class Person4 {
public:
    virtual void show(){}
};

class Teacher4 : public Person4{
    
};
class CppTeacher4 : public Teacher4{
    
};
class Student4 : public Person4{
    
};

class Computer{
public:
    void start(){}
};

class Notebook:public Computer {

};
        
class Company{
public:
    void test(Person4* p){
        Student4* p1 = dynamic_cast<Student4*>(p);
        if(p1){
            cout << "是学生" << endl;
        }

        Teacher4* p2 = dynamic_cast<Teacher4*>(p);
        if(p2){
            cout << "是老师" << endl;
        }
        // ... 略
    }
};
//
/**
 const对象只能调用const成员函数
 const对象中的mutable修饰的数据成员是允许修改的
 补充:
     const int* p           p指向 cosnt int
     int const *p           // 同上
     int* const p           // p 本身是const
     const int* const p     // p 本身是const,指向const int
 */
        
/**
 继承方式：一般用public继承
    public:private:protected:
    私有成员不能访问公开成员可以访问，特权是
    父类中可以用protected来作为访问限制
    这种成员称为保护成员，这种成员对外跟私有成员
    一样，可以在子类中访问，尽量不要使用protected，
    以免父子类间有太强的耦合
    private方式i继承过来后所有成员都成为子类的y私有成员
    protected方式继承过来之后，原来私有的还是私有的
    原来公开和保护的都变成保护的
 */
        
int main(int argc, const char * argv[]) {
    
    Pos a(20,80);
    cout << a->x << ","<< a->y << endl;
    a.move(30, -10);
    cout << a->x << ","<< a->y << endl;
    
    A* p = new A[3];
    cout << "sizeof A=" << sizeof(A) << endl;
    cout << "p=" << p << endl;
    delete[] p;
    p = NULL;
    
    R r(3,4);
    ++ ++r;
    cout << r << endl;
    -- --r;
    cout << r << endl;
    r++;
    cout << r << endl;
//    Person man;
//    Teacher t;
//    man.setname("apple");
//    man.eat("meat");
//    man.speak("hello");
//    t.setname("andy");
//    t.eat("rice");
//    t.speak("world");
//    t.setcourse("c++");
//    t.teach("123456");
    Person p1("man");
    Teacher t("andy","C++");
    p1.show();
    //  子类需要调用父类的成员函数需要用类名::成员函数
    p1.Person::show();
    t.show();
    
    CellPhone xiaomi;
    xiaomi.call("114");
    xiaomi.takephoto("风景");
    
    DoubleMan ma("aa","C++","1923");
    ma.teach("CS1902");
    ma.listen("318");
    cout << ma.Name() << endl;
//    多态
    Person* p2 = new Teacher("andy","swift");
    p2->show();
    delete p2;
    cout << "--11---end-----" << endl;
    
    Light lght;
    Car   bmw;
    Bike   yj;
    
    lght.stopvehicle(bmw);
    lght.stopvehicle(yj);
    cout << "--22---end-----" << endl;
    cout << sizeof(Animal) << endl;
    Person3 pp;
    Dog     pd;
    Jiafei  pj;
    pp.play(pd);
    pp.play(pj);
    /*
     虚函数表实现过程
     Animal      --- | &eat()
     虚函数表     --- | &shout()
    
     Cat         --- | &Cat::eat()
     虚函数表     --- | &Cat::shout()
     Dog         --- | &Dog::eat()
     虚函数表     --- | &Dog::shout()
  
     Cat         --- | &Cat::eat()
     虚函数表     --- | &Cat::shout()
     
     play(a)
     通过a.vptr的虚表指针去调用响应的函数
     a.eat()   === a.vptr[0]()
     a.shout() === a.vptr[1]()
     play(d)
     d.eat()   === d.vptr[0]()
     d.shout() === d.vptr[1]()
     */
    cout << "--33---end-----" << endl;
     /*无虚函数错误*/
//    Computer* comp = new Notebook();
//    dynamic_cast<Notebook*>(comp);
    Person4* ps = new Student4();
    Person4* pt = new Teacher4();
    Person4* pc = new CppTeacher4();
    
    Company apple;
    apple.test(ps);
    apple.test(pt);
    apple.test(pc);
    
    delete ps;
    delete pt;
    delete pc;
    
    return 0;
}
