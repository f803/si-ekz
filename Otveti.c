//1 Понятие алгоритмов сортировки. Задача сортировки. Ключ сортировки.

Алгоритм сортировки — это алгоритм для упорядочивания элементов в списке.
В случае, когда элемент списка имеет несколько полей, поле, служащее критерием порядка, называется ключом сортировки. 
На практике в качестве ключа часто выступает число, а в остальных полях хранятся какие-либо данные, никак не влияющие на работу алгоритма.

//2 Оценка алгоритмов сортировки.
  
Существует много различных алгоритмов сортировки. Все они имеют свои положительные стороны, но общие критерии оценки алгоритма сортировки таковы:

- Насколько быстро данный алгоритм сортирует информацию в среднем?
- Насколько быстро он работает в лучшем и худшем случаях?
- Естественно или неестественно он себя ведет?
- Переставляет ли он элементы с одинаковыми ключами?
  
Давайте подробнее рассмотрим эти критерии. Очевидно, что скорость работы любого алгоритма сортировки имеет большое значение. 
Скорость сортировки массива непосредственно связана с количеством сравнений и количеством обменов, происходящих во время сортировки, причем обмены занимают больше времени.
Сравнение происходит тогда, когда один элемент массива сравнивается с другим; обмен происходит тогда, когда два элемента меняются местами. 
Время работы одних алгоритмов сортировки растет экспоненциально, а время работы других логарифмически зависит от количества элементов.

Время работы в лучшем и худшем случаях имеет значение, если одна из этих ситуаций будет встречаться довольно часто. 
Алгоритм сортировки зачастую имеет хорошее среднее время выполнения, но в худшем случае он работает очень медленно.

Поведение алгоритма сортировки называется естественным, если время сортировки минимально для уже упорядоченного списка элементов, 
увеличивается по мере возрастания степени неупорядоченности списка и максимально, когда элементы списка расположены в обратном порядке. 
Объем работы алгоритма оценивается количеством производимых сравнений и обменов.
 
//3 Сортировка методом "Пузырька".
	
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
  }
  
void Bubble(int *arr){
    int i,j,c=0,p=0;
    for(i=0;i<size-1;i++)
      for(j=0;j<size-i-1;j++){c++;
        if(arr[j]>arr[j+1]){p++;
          swap(&arr[j], &arr[j + 1]);
        }
      }
  printf("compar=%d,reshuffle=%d\n",c,p);
  }

//4 Шейкер сортировка.

void Shaker(int *arr){
    int i,j,n1=0,n2=size-1,c=0,p=0;
    do{
      for(i=n2;i>n1;i--) {c++;
        if(arr[i-1]>arr[i]){p++;
          swap(&arr[i], &arr[i - 1]);
          j=i;
        }
      }
    n1=j;
    for(i=n1;i<=n2;i++){c++;
      if(arr[i-1]>arr[i]){
        swap(&arr[i], &arr[i - 1]);
        j=i;p++;
      }
    }
    n2=j-1;
    } while(n1<n2);
  printf("compar=%d,reshuffle=%d\n",c,p);
  }

//5 Сортировка методом простого выбора.

 void SelectionSort(int *arr){
    int i,j,im,temp,c=0,p=0;
    for(i=0;i<size-1;i++){
      im=i;
      for(j=i+1;j<size;j++){c++;
        if(arr[j]<arr[im])
        im=j;}
        c++;
        if(i!=im){
          p++;
          swap(&arr[im], &arr[i]);
        }
      }
    printf("compar=%d,reshuffle=%d\n",c,p);
    }

//6 Сортировка методом простого включения.

  void InsertSort(int *arr){
    int i,j,temp,c=0;
    double p=0;
    for(i=1;i<size;i++){
        temp=arr[i];p+=1./3;
        j=i-1;
        while(j>=0 && arr[j]>temp) {c++;
              arr[j+1]=arr[j];
              j=j-1;
          }
    arr[j+1]=temp;p+=1./3;
    }
  printf("compar=%d,reshuffle=%lf\n",c,p);
  }

//7 Сортировка Шелла.

void Shella(int *arr){
	int i,j,temp,step = size/2,c=0,p=0;
	while(step>0){
	  for(i=0;i<(size - step);i++){c++;
	    j=i;
	    while(j>=0 && arr[j]>arr[j+step]){
		c++;p++;
		temp=arr[j];
		arr[j]=arr[j+step];
		arr[j+step]=temp;
		j--;
		}
	  }
	step /=2;
	}
  printf("compar=%d,reshuffle=%d\n",c,p);
}

//8 Метод цепочек.

Технология сцепления элементов состоит в том, что элементы множества, которым соответствует одно и то же хеш-значение, связываются в цепочку-список.
В позиции номер i хранится указатель на голову списка тех элементов, у которых хеш-значение ключа равно i ; если таких элементов в множестве нет, в позиции i записан NULL.
  
На рисунке 1 демонстрируется реализация метода цепочек при разрешении коллизий. На ключ 002 претендуют два значения, которые организуются в линейный список.
  
//Здесь должна быть картинка

Каждая ячейка массива является указателем на связный список (цепочку) пар ключ-значение, соответствующих одному и тому же хеш-значению ключа.
Коллизии просто приводят к тому, что появляются цепочки длиной более одного элемента.
  
Операции поиска или удаления данных требуют просмотра всех элементов соответствующей ему цепочки, чтобы найти в ней элемент с заданным ключом. 
Для добавления данных нужно добавить элемент в конец или начало соответствующего списка, и, в случае если коэффициент заполнения станет слишком велик,
увеличить размер массива и перестроить таблицу.
  
При предположении, что каждый элемент может попасть в любую позицию таблицы с равной вероятностью и независимо от того, куда попал любой другой элемент,
среднее время работы операции поиска элемента составляет O(1+k), где k – коэффициент заполнения таблицы.
  
//9 Метод открытой адресации.

В отличие от хеширования с цепочками, при открытой адресации никаких списков нет, а все записи хранятся в самой хеш-таблице. 
Каждая ячейка таблицы содержит либо элемент динамического множества, либо��NULL.
В этом случае, если ячейка с вычисленным индексом занята, то можно просто просматривать следующие записи таблицы по порядку до тех пор,
пока не будет найден ключ K или пустая позиция в таблице. Для вычисления шага можно также применить формулу, которая и определит способ изменения шага.
На рисунке 2 разрешение коллизий осуществляется методом открытой адресации.
Два значения претендуют на ключ 002, для одного из них находится первое свободное (еще незанятое) место в таблице.

//Здесь должна быть картинка
	
При любом методе разрешения коллизий необходимо ограничить длину поиска элемента. Если для поиска элемента необходимо более 3 – 4 сравнений, 
то эффективность использования такой хеш-таблицы пропадает и ее следует реструктуризировать (т.е. найти другую хеш-функцию),
чтобы минимизировать количество сравнений для поиска элемента.
Для успешной работы алгоритмов поиска, последовательность проб должна быть такой, чтобы все ячейки хеш-таблицы оказались просмотренными ровно по одному разу.
Удаление элементов в такой схеме несколько затруднено. Обычно поступают так: заводят логический флаг для каждой ячейки, помечающий, удален ли элемент в ней или нет. 
Тогда удаление элемента состоит в установке этого флага для соответствующей ячейки хеш-таблицы, но при этом необходимо модифицировать процедуру поиска существующего элемента так,
чтобы она считала удаленные ячейки занятыми, а процедуру добавления – чтобы она их считала свободными и сбрасывала значение флага при добавлении. 
	
//10 Одноправленный список. Описание простейшего элемента.
	
Однонаправленный (односвязный) список – это структура данных, представляющая собой последовательность элементов, в каждом из которых хранится значение
и указатель на следующий элемент списка. В последнем элементе указатель на следующий элемент равен NULL.
	
	
Описание простейшего элемента такого списка выглядит следующим образом:

struct имя_типа { информационное поле; адресное поле; };

Где информационное поле – это поле любого, ранее объявленного или стандартного, типа;

Адресное поле – это указатель на объект того же типа, что и определяемая структура, в него записывается адрес следующего элемента списка.

Например:

struct Node {
             int key;//информационное поле
             Node*next;//адресное поле
            };
Информационных полей может быть несколько.

Например:

struct point {
              char*name;//информационное поле
              int age;//информационное поле
              point*next;//адресное поле
             };

//11 Операции с одноправленными списками. Ключ элемента списка.

Каждый элемент списка содержит ключ, который идентифицирует этот элемент. Ключ обычно бывает либо целым числом, либо строкой.
	
typedef struct Node{
  int val;
  struct Node *next;
}NODE,*pNODE;

typedef struct List{
  pNODE top;
  int len;
}LIST,*pLIST;

//создание нового списка
pLIST create_list(){
  pLIST pL;
  pL = (pLIST)malloc(sizeof(LIST));
    if(!pL) return NULL;
    pL->top = NULL;
    pL->len = 0;
    return pL;
}

//проверка наполнености списка
int isEmpty(pLIST pL){
  if(pL->top && pL->len) return 0;
    return 1;
}

//определение вставки следующего узла
pNODE GetPointer(pLIST pL,int date){
  if(isEmpty(pL)) return NULL;
  pNODE temp = pL->top;
    if(temp->val<=date) return temp;
  while(temp->next && temp->next->val>date)
    temp=temp->next;
    return temp;
}

//добавление в список нового элемента
int addNodeAfter(pLIST pL,pNODE pN, int newdate){
  pNODE pnew = (pNODE)malloc(sizeof(NODE));
  if(pnew){
    pnew->val = newdate;
    if(!pN){
      pnew->next = NULL;
      pL->top = pnew;
    }
    else
    if(pN == pL->top && newdate>pL->top->val){
      pnew->next = pL->top;
      pL->top = pnew;
    }
    else{
      pNODE temp = pN->next;
      pnew->next = temp;
      pN->next = pnew;
    }
    pL->len++;
    return 1;
  }
  return 0;
}

//просмотр элементов списка
void showList(pLIST pL){
  if(isEmpty(pL)) printf("List is empty!!\n");
  else{
    pNODE temp = pL->top;
    printf("Length List: %d\n",pL->len);
    while(temp){
      printf("adres: %p\t Value: %d\t next:%p\n", temp,temp->val,temp->next);
      temp = temp->next;
    }
  }
}

//нахождение в списке узла
pNODE findNode(pLIST pL,int date){
  if(isEmpty(pL)) return NULL;
  pNODE temp = pL->top;
  if(temp->val==date) return temp;
  while(temp->next && temp->next->val!=date) temp = temp->next;
  if(temp->next) return temp;
  return NULL;
}

//удаление узла
int delNode(pLIST pL,pNODE pN){
  if(!pN) return 0;
  pNODE temp = pN->next;
  pN->next = temp->next;
  free(temp);
  pL->len--;
  return 1;
}

//удаление всех узлов
void clearLIST(pLIST pL){
  while(pL->top->next) delNode(pL, pL->top);
  free(pL->top);
  pL->len--;
}

//удаление списка
void deleteList(pLIST pL){
  if(!isEmpty(pL)) clearLIST(pL);
  free(pL);
}

//12 Понятие дерева. Классификация деревьев

Дерево – это лес, состоящий из одного связного компонента (т.е. из одного дерева). (рекурсивное определение).

Дерево – это граф без циклов. (с точки зрения теории графов).

Дерево – древовидная структура данных, в которой значения всех узлов, размещённых правее некоторого узла, больше значений узлов, размещённых левее, 
причём это справедливо как для всего дерева, так и для любой его части.

Деревья или, в более широком смысле, древовидные структуры данных, представляют собой динамические связные структуры, отличающиеся от списков тем, 
что система связей не носит линейного характера, а образует ветви, подобно природному дереву.

Классификация

Эти структуры данных в общем случае можно разделить на две группы, которые отличаются друг от друга способом построения и (как следствие) реализацией процедур обработки – собственно деревья и пирамиды.

  двоичные(или бинарные) – имеющие не более двух ветвей;

  – с числом ветвей больше 2 – часто такие деревья называют мультивариантными (многопутевыми) или K-деревьями (т.е. K-мерными).

Важным признаком является состояние сбалансированности дерева и способы его достижения. Деревья могут быть:

  – сбалансированными;
  – идеально сбалансированными;
  – вырожденными;
  – отличающимися более или менее сильно от сбалансированных и от вырожденных.

Ещё один важный признак классификации – применение деревьев. Деревья поиска или сортировки.

//13 Операции с деревьями.
    
typedef struct node{
  int key;
  struct node *left, *right;
}NODE, *pNODE;

//добавление узла
pNODE addnode(int x, pNODE root){
  if (!root){
    root =(pNODE) malloc (sizeof(NODE));
    if (root){
      root->key=x;
      root->left=NULL;
      root->right=NULL;
  }
}
  else
    if (x<root->key)
      root->left=addnode (x,root->left);
    else
      root->right=addnode (x,root->right);
  return root;
}

//прохождение дерева
// нисходящее
void preorder (pNODE root){
  if (root){
    printf("%d;",root->key);
    preorder (root->left);
    preorder (root->right);
  }
}

//восходящее
void postorder(pNODE root){
  if (root){
    postorder (root->left);
    postorder (root->right);
    printf("%d;",root->key);
  }
}

//последовательное
void inorder (pNODE root){
  if (root){
    inorder (root->left);
    printf ("%d;",root->key);
    inorder (root->right);
  }
}

//поиск узла в дереве
pNODE find_tree (pNODE root, int val){
  if (!root) return NULL;
  if(val==root->key) return root;
  if(val<root->key) return find_tree(root->left, val);
  if(val>=root->key) return find_tree(root->right,val);
}

//поиск крайнего правого элемента
int rightmost (pNODE root){
  while (root->right)
    root=root->right;
  return root->key;
}

//удаление узла из дерева
pNODE del_tree (pNODE root, int val){
  if (!root) return NULL;
  if (root->key==val){
    if(!(root->left) && !(root->right)){
      free (root);
    return NULL;
    }
    if(!(root->right)&& root->left){
      pNODE temp= root->left;
      free(root);
      return temp;
    }
    if(!(root->left) && root->right){
      pNODE temp= root->right;
      free (root);
      return temp;
    }
    root->key=rightmost(root->left);
    root->left=del_tree(root->left,root->key);
    return root;
  }
  if (val< root->key){
    root->left=del_tree(root->left, val);
    return root;
  }
  if (val>=root->key){
    root->right=del_tree(root->right, val);
    return root;
  }
  return root;
}

//подсчет узлов
void Nnodes (pNODE root, int *p){
  if (!root) return;
    (*p)++;
    Nnodes(root->left, p);
    Nnodes(root->right, p);
}

//определение высоты дерева
void Height(pNODE root, int p,int* h){
  if(!root) return;
  p++;
  if(!(root->left) && !(root->right))
    if(p>*h) *h=p;
  Height(root->left,p,h);
  Height(root->right,p,h);
}

//удаление всех узлов
void del_all(pNODE *root){
  if (!*root) return;
  del_all (&(*root)->left);
  del_all (&(*root)->right);
  free (*root);
  *root = NULL;
}

//14 Сбалансированные деревья.

Максимальный эффект использования двоичного дерева поиска достигается, если оно сбалансировано – когда все узлы, кроме терминальных, 
имеют непустые и правый и левый соседние узлы; все поддеревья, начинающиеся с одного и того же уровня, имеют одинаковую высоту.

Сбалансированное бинарное дерево – максимально широкое и низкое.

Менее строгое, но практически более удобное определение сбалансированности дерева – дерево является сбалансированным, если для каждого узла исходящие ветви отличаются по 
высоте не более, чем на один уровень.

Для двоичного идеально сбалансированного дерева с максимально возможным (для идеальной сбалансированности) числом узлов существуют простые соотношения между этим числом узлов 
Nузлов и высотой дерева (т.е. числом уровней) nуровней :

Nузлов = 2Nуровней − 1

Nуровней = log2(Nузлов + 1)

Состояние сбалансированности часто оказывается настолько важным для тех областей, в которых деревья применяются, что для достижения этого состояния принимают специальные меры. 
Такими мерами являются либо та или иная операция балансировки (принудительной) дерева, в том числе включающая в себя упомянутые операции поворотов, либо использование 
специальных видов деревьев, обеспечивающих балансировку при каждой операции добавления или удаления узла.

//15 Рекурсивные функции. Этапы выполнения.

Рекурсия — вызов функции из неё же самой, непосредственно (простая рекурсия) или через другие функции (сложная или косвенная рекурсия), 
например, функция A вызывает функцию B, а функция B — функцию A.
  
Что происходит, если одна функция вызывает другую? В общих чертах следующее:

· в памяти размещаются параметры, передаваемые функции (но не параметры-переменные, т. к. они передаются по ссылке!);
· для внутренних переменных вызываемой функции также отводится новая область памяти (несмотря на совпадение их имен и типов с переменными вызывающей функции);
· запоминается адрес возврата в вызывающую функцию;
· управление передается вызванной функции.

// вычисление факториала
double Rec_Fact(int n){
  if (n <= 1)
    return 1.0;
  else 
    return Rec_Fact(n-1)*n;
}

// вычисление чисел Фибоначи
unsigned long fib(int n){
  if(n==0 || n==1)
    return 1;
  else
    return fib(n-1)+fib(n-2);
}

// возведения вещественного числа Х в целую степень N>=0
double Rec_step(float a,int b){
  if(b <= 0) 
    return 1.0;
  else
    return Rec_step(a,b-1)*a;
}

// быстрого возведения вещественного числа Х в целую степень N>=0
double rec_degree(double a,int b){
  double r;
  if(!b)
    return 1;
  if(!(b%2))
    return r=rec_degree(a,b/2), r*r;
  else 
    return a*rec_degree(a,b-1);
}

// вычисление НОД
int NOD_rec(int a,int b){
  if(!(a%b))
    return b;
  else
    return NOD_rec(b,a%b);
}

// печати числа в виде строки символа
void printd(int k){
  if(k<0){
    putchar('-');
    k= -k;}
  if(k/10)
    printd(k/10);
  putchar(k%10 +'0');
}

// вывода на печать символов строки в опратном порядке
void Reverse(){
  int ch;
  if((ch=getchar()) !='\r'){
    Reverse();
    putchar(ch);
  }
}

// вычисление суммы элементов массива
int sum(int *s,int n){
  if(n==1)
    return s[0];
  else
    return sum(s,n-1) + s[n-1];
}

//16 Формы рекурсивных функций.

Существует три разных формы рекурсивных программ:

1. Форма с выполнением действий до рекурсивного вызова (с выполнением действий на рекурсивном спуске).
2. Форма с выполнением действий после рекурсивного вызова (с выполнением действий на рекурсивном возврате).
3. Форма с выполнением действий как до, так и после рекурсивного вызова (с выполнением действий, как на рекурсивном спуске, так и на рекурсивном возврате).

//17 Виды рекурсий.
  
Рекурсия может быть прямой и косвенной.

В случае прямой рекурсии вызов функцией самой себя делается непосредственно в этой же функции:

      void f() {
      ............
      f();
      ............
      }

Косвенная рекурсия создаётся за счёт вызова данной функции из какой-либо другой функции, которая сама вызывалась из данной функции.

//18 Указатель на функцию.
  
Указатель на функцию представляет собой выражение или переменную, которые используются для представления адреса функции. Указатель на функцию содержит адрес первого байта в 
памяти, по которому располагается выполняемый код функции.
  
Адрес, присвоенный указателю, является входной точкой в функцию. Указатель может использоваться вместо имени функции. Он также позволяет передавать функции как обычные 
аргументы в другие функции.

Указатели на функции задаются следующим образом:

    1) void f() { } 
    2) void (*pf)() = &f; 
    3) pf();

В этом коде f - некоторая функция. Во второй строчке определяется переменная pf, которая является указателем на функцию, которая ничего не возвращает и не принимает ни одного 
аргумента. В определении pf ей присваивается адрес функции f. В третьей строке мы вызываем функцию по указатели pf(в данном случае будет вызвана функция f).

//19 Обобщенные алгоритмы.
  
Алгоритмы STL представляют собой обобщённые численные алгоритмы (заголовочный файл <numeric>). Это не какие-то особые вычислительные методы, как можно подумать исходя из 
названия. Это алгоритмы, позволяющие применять общеизвестные библиотечные или свои собственные вычислительные функции ко всей совокупности элементов контейнера.

А поскольку так, то и вызываются они подобно всем другим алгоритмам STL. Используются такие обобщённые алгоритмы, главным образом в математических вычислениях применительно к 
контейнерам, содержащим числовые элементы.

Перечислим представленные STL обобщённые численные алгоритмы: iota (создание монотонно возрастающей последовательности), accumulate (накопление), inner_product 
(скалярное произведение), partial_sum (частичная сумма), adjacent_difference (смежная разность).

//20 Стек. Примеры. Основные операции над стеком.

Стек — абстрактный тип данных, представляющий собой список элементов, организованных по принципу LIFO (англ. last in — first out, «последним пришёл — первым вышел»).

Программный вид стека используется для обхода структур данных, например, дерево или граф. 
При использовании рекурсивных функций также будет применяться стек, но его аппаратный вид. Кроме этих назначений, стек используется для организации стековой машины, 
реализующей вычисления в обратной польской записи. Примером использования стековой машины является программа Unix dc.
Для отслеживания точек возврата из подпрограмм используется стек вызовов.
Арифметические сопроцессоры, программируемые микрокалькуляторы и язык Forth используют стековую модель вычислений.
Идея стека используется в стековой машине среди стековых языков программирования.

Операции стека:
  1) Проверка стека на пустоту
  2) Дабавление элемента
  3) Вывод стека на экран
  4) Извлечение элемента из стека
  5) Очистка стека
  5) Создание стека

//21 Создание стека. Функция создания нового стека.

typedef struct Node{
  char val;
  struct Node *next;
}NODE,*pNODE;

typedef struct Stack{
  pNODE top;
  int len;
}STACK,*pSTACK;

pSTACK createstack(){
  pSTACK ps;
  ps = (pSTACK)malloc(sizeof(STACK));
    ps->top = NULL;
    ps->len = 0;
    return ps;
}

// 22 Функция проверки наполненности стека.

int isempty(pSTACK ps){
  if(ps->top) return 0;
  return 1;
}

// 23 Функция добавления элемента в стек.

void push(pSTACK ps, char value){
  pNODE p = (pNODE)malloc(sizeof(NODE));
  p->val = value;
  p->next = ps->top;
  ps->top = p;
  ps->len++; 
}

// 24 Функция извлечения элемента из стека.

char pop(pSTACK ps){
  pNODE p = ps->top;
  int c = p->val;
  ps->top=p->next;
  free(p);
  ps->len--;
  return c;
}

// 25 Функция вывода стека на экран.

void show(pSTACK ps){
  pNODE p = ps->top;
    if(isempty(ps))puts("stack empty");
    else
    while(p){
      printf("%c", p->val);
      p = p->next;
    }
}

// 26 Функция очистки стека.

void clearstack(pSTACK ps){
  while(!isempty(ps))
    pop(ps);
    free(ps);
}

// 27 Тело программы.

int main(void){
  setlocale(LC_CTYPE,"Russian");
  pSTACK ps = createstack();
  char c;
  for(c='a';c<='{';c++)
    push(ps,c);
  while(!isempty(ps)){
    pop(ps);
    show(ps);
    printf("\n");
  }
  return 0;
}

// 28 Очередь. Операции очереди.

Очередью называется упорядоченный набор элементов, которые могут исключаться с одного ее конца (называемого началом очереди), 
а включаться с другого конца (называемого концом очереди).
Операции очереди:
  1) Проверка очереди на пустоту
  2) Дабавление элемента
  3) Вывод очереди на экран
  4) Изъятие элемента из очереди
  5) Очистка очереди
  6) Создание очереди

// 29 Области применения очереди.

Очередь в программировании используется, как и в реальной жизни, когда нужно совершить какие-то действия в порядке их поступления, выполнив их последовательно. 
Примером может служить организация событий в Windows. Когда пользователь оказывает какое-то действие на приложение, то в приложении не вызывается соответствующая процедура 
(ведь в этот момент приложение может совершать другие действия), а ему присылается сообщение, содержащее информацию о совершенном действии, это сообщение ставится в очередь, 
и только когда будут обработаны сообщения, пришедшие ранее, приложение выполнит необходимое действие.

Области применения очередей могут быть разделены на две группы – системное применение и прикладное. К применению очередей в системных целях относятся:

 - диспетчеризация задач операционной системой;
 - буферизация ввода/вывода;

Прикладное применение:

 - моделирование процессов (например, систем массового обслуживания);
 - использование очередей как вспомогательных структур данных в каких-либо алгоритмах (например, при поиске в графах).

// 30 Реализация очереди. Функция создания очереди.

typedef struct Node{
  int val;
  struct Node *next;
}NODE,*pNODE;

typedef struct queue{
  NODE *beg, *end;
  int len;
}QUEUE,*pQUEUE;

pQUEUE create(){
  pQUEUE pQ;
  pQ = (pQUEUE)malloc(sizeof(QUEUE));
  pQ->beg = NULL;
  pQ->end = NULL;
  pQ->len = 0;
  return pQ;
}

// 31 Функция проверки очереди на пустоту. Функция добавления элемента.

int isempty(pQUEUE pQ){
  if(pQ->beg == NULL) return 1;
  return 0;
}

void put(pQUEUE pQ, float value){
  pNODE pn;
  pn = (pNODE)malloc(sizeof(NODE));
  pn->next = NULL;
  pn->val = value;
  if(pQ->end != NULL) pQ->end->next = pn;
  else pQ->beg = pn;
  pQ->end = pn;
  pQ->len++;
}

// 32 Функция вывода очереди на экран. Функция изъятия элемента из очереди.

void show(pQUEUE pQ){
  pNODE p = pQ->beg;
    if(isempty(pQ))puts("empty");
    while(p){
      printf("%d", p->val);
      p = p->next;
    }
    printf("\n");
}

float take(pQUEUE pQ){
  pNODE p = pQ->beg;
  float c=p->val;
  pQ->beg = p->next;
  free(p);
  pQ->len--;
  return c;
}

// 33 Функция очистки очереди. Тело программы.

void ClearQueue(pQUEUE pQ){
  while(!isempty(pQ)){
    take(pQ);
  }
  free(pQ);
}

int main(void){
  pQUEUE pQ = create();
  int i;
  for(i = 1; i < 11;i++){
    put(pQ,i);
  }
  show(pQ);
  while(!isempty(pQ)){
    take(pQ);
    show(pQ);
  }
}
