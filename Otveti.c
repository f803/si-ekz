//20 Стек. Примеры. Основные операции над стеком.

/*

*/

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

/*
Очередью называется упорядоченный набор элементов, которые могут исключаться с одного ее конца (называемого началом очереди), 
а включаться с другого конца (называемого концом очереди).
Операции очереди:
  1) Проверка очереди на пустоту
  2) Дабавление элемента
  3) Вывод очереди на экран
  4) Изъятие элемента из очереди
  5) Очистка очереди
*/

// 29 Области применения очереди.

/*
Очередь в программировании используется, как и в реальной жизни, когда нужно совершить какие-то действия в порядке их поступления, выполнив их последовательно. 
Примером может служить организация событий в Windows. Когда пользователь оказывает какое-то действие на приложение, то в приложении не вызывается соответствующая процедура 
(ведь в этот момент приложение может совершать другие действия), а ему присылается сообщение, содержащее информацию о совершенном действии, это сообщение ставится в очередь, 
и только когда будут обработаны сообщения, пришедшие ранее, приложение выполнит необходимое действие.

Области применения очередей могут быть разделены на две группы – системное применение и прикладное. К применению очередей в системных целях относятся:

  диспетчеризация задач операционной системой;
  буферизация ввода/вывода;

Прикладное применение:

  моделирование процессов (например, систем массового обслуживания);
  использование очередей как вспомогательных структур данных в каких-либо алгоритмах (например, при поиске в графах).
*/

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
