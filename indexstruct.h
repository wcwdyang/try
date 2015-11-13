#ifndef INDEXSTRUCT
#define INDEXSTRUCT
template <class T>
class IndexStruct
{

   public:  IndexStruct();
           ~IndexStruct();
           virtual void insert(T)=0;
           virtual void delet()=0;
};
template <class T>
IndexStruct<T>::IndexStruct()
{

}
template <class T>
IndexStruct<T>::~IndexStruct()
{

}

#endif // INDEXSTRUCT

