


 struct thread
{
	void (*f)(void* arg) function;
	void* arg;

	void *thread_s_pointer;

	void *stack_pointer;
	void *base_pointer;

	struct thread *next;
};

struct thread *current = NULL;


struct thread thread_create(void (*f)(void* arg) f_pointer, void* arg)
{
	struct thread temp;
	temp.thread_s_pointer = malloc(4096);
	temp.function = f_pointer;
	temp.arg = arg;

	return temp;
}

void thread_add_runqueue(struct thread *t)
{
	struct thread *temp;

	if(current == NULL){
		current = t;
	}else{
		temp = current->next;
		current->next = t;
		t->next = temp;
	}
}