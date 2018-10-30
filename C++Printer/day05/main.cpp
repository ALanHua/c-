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
    cout << "-----end-----" << endl;
    return 0;
}
