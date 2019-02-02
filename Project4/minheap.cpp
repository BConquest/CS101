
typedef struct heap_el_t
{
     char key;
     int freq;
     heap_el_t *left = nullptr;
     heap_el_t *right = nullptr;
} heap_el_t;

typedef struct heap_t
{
     int max_size;
     int current_size;
     heap_el_t *heap;
} heap_t;

heap_t *create_heap(int size)
{
     heap_t *hp;
     hp = new heap_t;
     hp->heap = new heap_el_t[size];
     hp->max_size = size;
     hp->current_size = 0;
     return hp;
}

int heap_empty(heap_t *hp)
{
     return(hp->current_size == 0);
}

heap_el_t *find_min(heap_t *hp)
{
     return(hp->heap);
}

int insert(char new_key, int new_freq, heap_t *hp)
{   
    if(new_freq == 0)
    {
        return 0;
    }
     if(hp->current_size < hp->max_size)
     {
        int gap = hp->current_size++;
        while(gap > 0 && new_freq < (hp->heap[(gap-1)/2]).freq)
        {
            (hp->heap[gap]).key = (hp->heap[(gap-1)/2]).key;
            (hp->heap[gap]).freq = (hp->heap[(gap-1)/2]).freq;
            (hp->heap[gap]).left = (hp->heap[(gap-1)/2]).left;
            (hp->heap[gap]).right = (hp->heap[(gap-1)/2]).right;
            gap = (gap-1)/2;
        }

        (hp->heap[gap]).key = new_key;
        (hp->heap[gap]).freq = new_freq;
        (hp->heap[gap]).left = nullptr;
        (hp->heap[gap]).right = nullptr;
        return(0);
     }
     else
          return(-1);
}

int insert(heap_el_t* temp, heap_t* hp)
{
     if(hp->current_size < hp->max_size)
     {
        int gap = hp->current_size++;
        while(gap > 0 && temp->freq < (hp->heap[(gap-1)/2]).freq)
        {
            (hp->heap[gap]).key = (hp->heap[(gap-1)/2]).key;
            (hp->heap[gap]).freq = (hp->heap[(gap-1)/2]).freq;
            (hp->heap[gap]).left = (hp->heap[(gap-1)/2]).left;
            (hp->heap[gap]).right = (hp->heap[(gap-1)/2]).right;
            gap = (gap-1)/2;
        }

        (hp->heap[gap]).key = temp->key;
        (hp->heap[gap]).freq = temp->freq;
        (hp->heap[gap]).left = temp->left;
        (hp->heap[gap]).right = temp->right;
        return(0);
     }
     else
          return(-1);
}


heap_el_t *delete_min(heap_t *hp)
{
     heap_el_t *del_obj = new heap_el_t;
     int reached_top = 0;
     int gap, newgap, last;
     if(hp->current_size == 0)
     {
          return(nullptr);
     }

     del_obj->key =  hp->heap->key;
     del_obj->freq =  hp->heap->freq;
     del_obj->left =  hp->heap->left;
     del_obj->right =  hp->heap->right;
     gap = 0;

     while(!reached_top)
     {
          if(2*gap + 2 < hp->current_size)
          {
               if((hp->heap[2*gap+1]).freq < (hp->heap[2*gap+2]).freq)
                    newgap = 2*gap + 1;
               else
                    newgap = 2*gap + 2;
               (hp->heap[gap]).key = (hp->heap[newgap]).key;
               (hp->heap[gap]).freq = (hp->heap[newgap]).freq;
               (hp->heap[gap]).left = (hp->heap[newgap]).left;
               (hp->heap[gap]).right = (hp->heap[newgap]).right;
               gap = newgap;
          }
          else if(2*gap + 2 == hp->current_size)
          {
               newgap = 2*gap+1;
               (hp->heap[gap]).key = (hp->heap[newgap]).key;
               (hp->heap[gap]).freq = (hp->heap[newgap]).freq;
               (hp->heap[gap]).right = (hp->heap[newgap]).right;
               (hp->heap[gap]).left = (hp->heap[newgap]).left;
               hp->current_size -= 1;
               return(del_obj);
          }
          else
               reached_top = 1;
     }
     last = --hp->current_size;
     while(gap > 0 && (hp->heap[last]).freq < (hp->heap[(gap-1)/2]).freq)
     {
          (hp->heap[gap]).key = (hp->heap[(gap-1)/2]).key;
          (hp->heap[gap]).freq = (hp->heap[(gap-1)/2]).freq;
          (hp->heap[gap]).left = (hp->heap[(gap-1)/2]).left;
          (hp->heap[gap]).right = (hp->heap[(gap-1)/2]).right;
          gap = (gap-1)/2;
     }

     (hp->heap[gap]).key = (hp->heap[last]).key;
     (hp->heap[gap]).freq = (hp->heap[last]).freq;
     (hp->heap[gap]).left = (hp->heap[last]).left;
     (hp->heap[gap]).right = (hp->heap[last]).right;
     return (del_obj);
}

void remove_heap(heap_t *hp)
{
     delete(hp->heap);
     delete(hp);
}
