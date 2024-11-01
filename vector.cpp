struct subvector {
     int *mas;
     unsigned int top; 
     unsigned int capacity;
};
bool resize(subvector*qv, unsigned int new_capacity);
bool init(subvector*qv){
    qv-> mas = nullptr;
    qv->top = 0;
    qv-> capacity = 0;
    return true;
} // инициализация пустого недовектора (top и capacity по нулям, а mas это NULL)
bool push_back(subvector*qv, int d){
    if(qv->top == qv->capacity){
        if(qv->capacity == 0){
            resize(qv, 1);
        }
        else{
            resize(qv,2* qv->capacity );
        }
    }
    *(qv->mas + qv->top) = d;
    qv->top++;
    return true;
} // добавление элемента в конец недовектора с выделением дополнительной памяти при необходимости
int pop_back(subvector*qv){
    if(qv->top>0){
        qv->top --;
        return *(qv->mas + qv->top);
    }
    return 0;
} // удаление элемента с конца недовектора, значение удаленного элемента вернуть (если недовектор пустой, вернуть ноль)
bool resize(subvector*qv, unsigned int new_capacity){
    int *new_data = new int[new_capacity];
    for(int i =0; i <((new_capacity<qv->top) ? new_capacity:qv->top);i++){
        *(new_data + i) = *(qv->mas + i);
    }
    delete[] qv->mas;
    qv->mas = new_data;
    qv->capacity = new_capacity;
    return true;

} // увеличить емкость недовектора (можно использовать и для уменьшения - тогда, в рамках данной реализации, если top меньше новой capacity, то копируем только то, что влезает, и уменьшаем top до capacity)
void shrink_to_fit(subvector*qv){
    resize(qv, qv->top);
} // очистить неиспользуемую память, переехав на новое место с уменьшением capacity до top
void clear(subvector *qv){
    qv->top = 0;
} // очистить содержимое недовектора, занимаемое место при этом не меняется
void destructor(subvector*qv){
    delete[] qv-> mas;
    qv->mas = nullptr;
    qv->top = 0;
    qv->capacity = 0;
}// очистить всю используемую память, инициализировать недовектор как пустой