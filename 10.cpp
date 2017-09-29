#ifndef SORT_NAME
#error "Must declare SORT_NAME"
#endif

#ifndef SORT_TYPE
#error "Must declare SORT_TYPE"
#endif

#ifndef SORT_CMP
#define SORT_CMP(x, y)  ((x) < (y) ? -1 : ((x) == (y) ? 0 : 1))
#endif

#define SORT_CONCAT(x, y)    x ## _ ## y
#define SORT_MAKE_STR1(x, y) SORT_CONCAT(x,y)
#define SORT_MAKE_STR(x)     SORT_MAKE_STR1(SORT_NAME,x)

// делает имя функции наподобие int_mergesort(), 
// по которому надо вызывать сортировку 
#define MERGE_SORT  SORT_MAKE_STR(mergesort)
#define MERGE       SORT_MAKE_STR(merge)
#ifdef __cplusplus
extern "C" { 
#endif
void MERGE_SORT  (SORT_TYPE *dst, const size_t size);
#ifdef __cplusplus
};
#endif

#ifndef SORT_NOCODE_GEN

#ifndef MIN
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#endif

/*
  Слияние 2-х последовательно расположенных в a[], 
  начиная с индекса start уже упорядоченных массивов, размером size элементов.
  Результат размещается в tmp[] (тоже с индекса start)
  n -- размер всего сортируемого массива a[]
 */
static void
MERGE (SORT_TYPE a[], SORT_TYPE tmp[], size_t first, size_t size, size_t n)
{
  size_t second = first + size,   // начало второго массива
    end1 = MIN(second, n),        // конец первого массива 
                                  // (дело тут в том, что второго может и не быть...)
    end2 = MIN(second + size, n), // конец второго массива 
    i = first;                    // индекс для текущего элемента результата в tmp[]

  while (first < end1 && second < end2)
    tmp[i++] = SORT_CMP(a[first], a[second]) <= 0 ? a[first++] : a[second++];
  while (first < end1) // остались элементы первого
    tmp[i++] = a[first++];
  while (second < end2) // или второго
    tmp[i++] = a[second++];
}

void 
MERGE_SORT (SORT_TYPE *dst, const size_t n)
{
  SORT_TYPE *tmp = (typeof(tmp))malloc(n * sizeof(*tmp));
  size_t l = 1, // размер уже упорядоченных подмассивов
    i;          // индекс пары последовательных слияющихся подмассивов

  // начнем слияние с последовательно расположенных подмассивов
  // из одного элемента
  while (l < n) { 
    for (i = 0; i < n; i += 2 * l)
      MERGE(dst, tmp, i, l, n);
    // теперь уже отсортированные подмассивы вдвое длинее, но они в tmp[]
    l *= 2;
    for (i = 0; i < n; i += 2 * l)
      MERGE(tmp, dst, i, l, n);
    // а тут их размер опять удвоился и они уже в нужном месте (в a[])
    l *= 2;
  }

  free(tmp);
}

#endif // SORT_NOCODE_GEN

#undef SORT_CONCAT
#undef SORT_MAKE_STR1
#undef SORT_MAKE_STR
