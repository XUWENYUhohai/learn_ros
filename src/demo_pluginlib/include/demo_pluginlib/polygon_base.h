#ifndef _POLYGON_BASE_H_
#define _POLYGON_BASE_H_
//标识符以头文件名全部大写命名，且.变为_,前后加上_
namespace polygon_base
{
    class RegularPolygon
    {
    public:
        virtual void initialize(double side_length) = 0;
        virtual double area() = 0;
        virtual ~RegularPolygon(){}

    protected:
        RegularPolygon(){}//基类必须提供无参构造函数，所以关于多边形的边长没有通过构造函数而是通过单独编写的initialize函数传参。
    };
}

#endif