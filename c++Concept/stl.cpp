// there are 4 components of stl 
// 1. Algorithms
// 2. Containers
    //there are three types of container
   // a. Sequence Containers
        //stack
        //queue
        //deque
        //vector
        //list

  // b. Associative Containers
        //set
        //map
        //multiset
        //multimap

// c. Derived container
       //unorder set
       //unorder map
       
// 3. Iterators
// 4. Function Objects
// STL is a collection of generic containers, algorithms, and iterators. It is a part of the
//  C++ Standard Library.


//templates are expanded at compile time 
//idea is simple that source code contains  the single code 
//which is used to generate multiple codes 
//so compiled code contains may contain multiplecopies of same class and function
template <typename T>
T MY_Max(T x ,T y){
    return (x>y)? x :y;
}