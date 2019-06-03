/*
结构体:
	由于数组只能存放相同类型的数据，所以拥有其局限性。当需要存放不同类型的多个数据时，这时候就要使用到结构体
	#在C语言中，结构体只能存放变量，不能存放函数。当然，如果是一个指针指向一个函数是可以的。

结构体的声明及定义

	struct	Stu{
		char name[50];
		int score;
	}
	需要注意的是，在这里，struct Stu整体才是一个变量类型

	typedef:代表对一个类型取类型别名，使用方法为typedef 原类型名 新类型名
	define:对一个单位做简单替换 使用方法 define 单位名 数据
	define和typedef的区别：define只是做一个简单替换，而typedef是在取类型别名
		define在预处理阶段就完成了，typedef在编译阶段才完成
*/
/*
关于结构体的访问:
	只要访问到结构体变量本身，就能访问到该结构体变量所拥有的所有属性，通过【结构体变量名.属性】来实现
*/
/*
结构体变量的内存管理
	结构体内存大小，遵循字节对齐的原则：就是说，结构体内开辟的每一个单元的内存空间大小，都会按照最大成员变量的内存大小去开辟

	还存在一个更大层次的字节对齐：这跟系统的操作系统有关，32位系统，每一次读取数据，最多读取到32位，同理64位系统每次读取数据，最多读取到64位。基于这个原则，当存在以下情况，满足较小级别的字节对齐，却不满足较大级别的字节对齐时，肯定是优先去满足较大级别字节对齐要求	
*/
/*
结构体和数组：
	结构体和数组并不存在大小关系，这两者可以相互包含，也就是说，结构体内可以存放数组，数组内也可以存放结构体
*/
/*
结构体和数组不同，数组不能直接整体赋值，而结构体可以
就是说：只要两个结构体的类型相同，那么这两个结构体变量可以直接用‘=’进行整体赋值
STU stu1;
STU stu2;
允许 stu1=stu2这样的操作
这个赋值操作的内部实现，其实就是将一个结构体内的所有数据，一个字节一个字节的拷贝过去。
所以，还存在这样的可能：两个不同类型的结构体，同时强转成void*或者同一个类型的结构体后，可以进行相互赋值的操作，但是由于内部的结构是不同的，所以会发生数据错误。在设计当中，应当避免这种情况的出现
*/




















