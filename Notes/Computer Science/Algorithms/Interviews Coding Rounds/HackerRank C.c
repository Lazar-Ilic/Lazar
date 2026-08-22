/*
I might go through these at some point and sharpen them up like I might between minutes 10 and 20 of a Hudson River Trading, Citadel, Optiver, etc. C coding round. Some of these are fundamentally OK copy and pasted codes.
*/

//----------

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	char s[100];
	scanf("%[^\n]%*c", &s);
	printf("Hello, World!\n");
	printf(s);   
	return 0;
}

//----------

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	char ch;
	scanf("%c", &ch);
	printf("%c\n", ch);
	char s[1000];
	scanf("%s", s);
	scanf("\n");
	printf("%s\n", s);
	char t[1000];
	scanf("%[^\n]%*c", t);
	printf("%s\n", t);
	return 0;
}

//----------

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d %d\n", m + n, m - n);
	float a, b;
	scanf("%f%f", &a, &b);
	printf("%.1f %.1f\n", a + b, a - b);
	return 0;
}

//----------

#include <stdio.h>

int max_of_four(int a, int b, int c, int d){
	return fmax(fmax(a, b), fmax(c, d));
}

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int ans = max_of_four(a, b, c, d);
	printf("%d", ans);
	return 0;
}

//----------

#include <stdio.h>

void update(int *a,int *b) {
	int c = (*a) + (*b);
	(*b) = abs((*a) - (*b));
	(*a) = c;
}

int main() {
	int a, b;
	int *pa = &a, *pb = &b;
	scanf("%d %d", &a, &b);
	update(pa, pb);
	printf("%d\n%d", a, b);
	return 0;
}

//----------

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int a, b;
	scanf("%d\n%d", &a, &b);
	char *avs[]={"one","two","three","four","five","six","seven","eight","nine"};
  	for(int c = fmax(a,1); c <= fmin(9, b); c++)printf("%s\n",avs[c-1]);
	for(int c = 10; c <= b-1; c+=2)printf("even\nodd\n");
	if(b%2==0 && b >= 10)printf("even\n");
	return 0;
}

//----------

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	//Complete the code to calculate the sum of the five digits on n.
	int answer = 0;
	while(n > 0) {
		answer += n % 10;
		n /= 10;
	}
	printf("%i\n", answer);
	return 0;
}

//----------

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k) {
	int z = 0;
	while(((k - 1) & (1 << z)) != 0) z++;
	printf("%d\n", k - 2 + (((k - 1) | (1 << z)) <= n));
	printf("%d\n",(k > 3) * (k - 2 + (((k - 1) & (k - 2)) > 0)));
	printf("%d\n",(n > 2) * (k - 1));
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	calculate_the_maximum(n, k);
	return 0;
}

//----------

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
  	int len = 2 * n - 1;
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len; j++) {
			int min_val = fmin(fmin(i, j), fmin(len - i - 1, len - j - 1));
			printf("%d ", n - min_val);
		}
		printf("\n");
	}
	return 0;
}

//----------

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int *arr = (int*)malloc(n * sizeof(int));
	int answer = 0;
	for(int a = 0; a < n; a++){
		scanf("%d", arr[a]);
		answer += arr[a];
	}
	free(arr);
	printf("%d\n", answer);
	return 0;
}

//----------

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num, *arr, i;
	scanf("%d", &num);
	arr = (int*) malloc(num * sizeof(int));
	for(i = 0; i < num; i++) scanf("%d", arr + i);
	for(i = 0; i < (num + 1) / 2; i++){
		int j = *(arr + i);
		*(arr + i) = *(arr + num - 1 - i);
		*(arr + num - 1 - i) = j;
	}
	for(i = 0; i < num; i++) printf("%d ", *(arr + i));
	return 0;
}

//----------

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	char *s;
	s = malloc(1024 * sizeof(char));
	scanf("%[^\n]", s);
	s = realloc(s, strlen(s) + 1);
	for (char *c = s; *c != NULL; c++) if (*c == ' ') *c = '\n';
	printf("%s", s);
	return 0;
}

//----------

#include <stdio.h>
#include <stdlib.h>

int* total_number_of_books;

int** total_number_of_pages;

int main() {
	int total_number_of_shelves;
	scanf("%d", &total_number_of_shelves);
	int total_number_of_queries;
	scanf("%d", &total_number_of_queries);
	total_number_of_books = (int*)malloc(sizeof(int)*total_number_of_shelves);
	total_number_of_pages = (int**)malloc(sizeof(int*)*total_number_of_shelves);
	for(int i = 0; i < total_number_of_shelves; i++){
		total_number_of_books[i] = 0;
		total_number_of_pages[i] =( int*)malloc(sizeof(int));
	}
	while (total_number_of_queries--) {
		int type_of_query;
		scanf("%d", &type_of_query);
		if (type_of_query == 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			*(total_number_of_books+x) += 1;
			*(total_number_of_pages+x) = realloc(*(total_number_of_pages + x), *(total_number_of_books + x) * sizeof(int));
			*(*(total_number_of_pages + x) + *(total_number_of_books + x) - 1) = y;
		}
		else if (type_of_query == 2) {
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%d\n", *(*(total_number_of_pages + x) + y));
		}
		else {
			int x;
			scanf("%d", &x);
			printf("%d\n", *(total_number_of_books + x));
		}
	}
	if (total_number_of_books) free(total_number_of_books);
	for (int i = 0; i < total_number_of_shelves; i++) {
		if (*(total_number_of_pages + i)) free(*(total_number_of_pages + i));
	}
	if (total_number_of_pages) free(total_number_of_pages);
	return 0;
}

//----------

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int find_nth_term(int n, int a, int b, int c) {
	if (n <= 3) {
		if(n == 1) return a;
		else if(n == 2) return b;
		else if(n == 3) return c;
		else return -1337;
	}
	int d = 0;
	while(n>3){
		d = c + b + a;
		a = b;
		b = c;
		c = d;
		n--;
	}
	return c;
}

int main() {
	int n, a, b, c;
	scanf("%d %d %d %d", &n, &a, &b, &c);
	int ans = find_nth_term(n, a, b, c);
	printf("%d", ans); 
	return 0;
}

//----------

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
	int answer = 0;
	for(int a = (gender == 'g'); a < number_of_students; a += 2) answer += *(marks + a);
	return answer;
}

int main() {

//----------

int lexicographic_sort(const char* a, const char* b) {
	return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
	return strcmp(b, a);
}

#define CHARS 26
int distinct_chars(const char *a) {
	int dist = 0;
	int chars[CHARS] = {0};
	while (*a != '\0') {
		int chr = (*a++) - 'a';
		if (chr < CHARS) chars[chr]++;
	}
	for (int i = 0; i < CHARS; i++) if (chars[i]) dist++;
	return dist;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
	int res = distinct_chars(a) - distinct_chars(b);
	return (res) ? res : lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
	int res = strlen(a) - strlen(b);
	return (res) ? res : lexicographic_sort(a, b);
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
	int sorted = 0;
	int top = len - 1;
	while (!sorted) {
		sorted = 1;
		for (int i = 0; i < top; i++) {
			if (cmp_func(arr[i], arr[i + 1]) > 0) {
				char *tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				sorted = 0;
			}
		}
		top--;
	}
}

//----------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s){
	// Find non-increasing suffix
	int i = n - 1;
	while(i > 0 && strcmp(s[i - 1], s[i]) >= 0) i--; // find key
	if (i <= 0) return 0;
	// Swap key with its successor in suffix
	int j = n - 1;
	while(strcmp(s[i - 1], s[j]) >=0 ) j--; // find rightmost successor to key
	char *tmp = s[i - 1];
	s[i - 1] = s[j];
	s[j] = tmp;
	// Reverse the suffix
	j = n-1;
	while(i < j) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
	return 1;
}

int main()

//----------

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000

int sum (int count,...) {
	int sum = 0;
	va_list values;
	va_start (values, count);
	for(int i = 0; i < count; i++) sum += va_arg (values, int);
	va_end(values);
	return sum;
}

int min (int count,...) {
	int min = MAX_ELEMENT, test;  
	va_list values;
	va_start (values, count);
	for(int i = 0; i < count; i++){
		test = va_arg (values, int);
		if(min > test) min = test;
	}
	va_end (values);
	return min;
}

int max (int count,...) {
	int max = MIN_ELEMENT, test;
	va_list values;
	va_start (values, count);
	for(int i = 0; i < count; i++){
		test = va_arg (values, int);
		if(max < test) max = test;
	}
	va_end (values);
	return max;
}

int test_implementations_by_sending_three_elements() {

//----------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
	return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
	return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
	return document[k-1];
}

char** split_string(char* text, char delim) {
	assert(text != NULL);
	char** result = malloc(1*sizeof(char*));
	int size = 1;
	char* temp = strtok(text, &delim);
	*result = temp;
	while(temp != NULL) {
		size++;
		result = realloc(result,size*sizeof(char*));
		temp = strtok(NULL, &delim);
		result[size-1] = temp;
	}
	return result;
}

char**** get_document(char* text) {
	assert(text != NULL);
	char** paragraphs = split_string(text, '\n');
	int npar = 0;
	while (paragraphs[npar] != NULL) npar++;
	char**** doc = malloc((npar + 1)*sizeof(char***));
	doc[npar] = NULL; 
	int i = 0;
	while (paragraphs[i] != NULL) {
		char** sentences = split_string(paragraphs[i], '.');
		int nsen = 0;
		while(sentences[nsen] != NULL) nsen++;
		doc[i] = malloc((nsen + 1) * sizeof(char**));
		doc[i][nsen] = NULL;
		int j = 0;
		while (sentences[j] != NULL) {
			doc[i][j] = split_string(sentences[j], ' ');
			j++;
		}
		i++;
	}
	return doc; 
}

//----------

#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41

typedef struct {
	int height;
	int length;
	int width;
}box;

int get_volume(box b) {
	return b.length * b.height * b.width;
}

int is_lower_than_max_height(box b) {
	return b.height < 41 ? 1 : 0;
}

int main()

//----------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle {
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle *tr, int n) {
	int *p=malloc(n*sizeof(int));
	for(int i = 0; i < n; i++) {
		float a = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
		p[i] = (a * (a - tr[i].a) * (a - tr[i].b) * (a - tr[i].c));
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(p[j] > p[j + 1]) {
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				temp = tr[j].a;
				tr[j].a = tr[j + 1].a;
				tr[j + 1].a = temp;
				temp = tr[j].b;
				tr[j].b = tr[j + 1].b;
				tr[j + 1].b = temp;
				temp = tr[j].c;
				tr[j].c = tr[j + 1].c;
				tr[j + 1].c = temp;
			}
		}
	}
}

int main()

//----------

#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6

struct package {
	char* id;
	int weight;
};

typedef struct package package;

struct post_office {
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town {
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;

#include <string.h>

void print_all_packages(town t) {
	printf("%s:\n", t.name);
	for(int i = 0; i < t.offices_count; i++){
		printf("\t%d:\n", i);
		for(int j = 0; j < t.offices[i].packages_count; j++){
			printf("\t\t%s\n", t.offices[i].packages[j].id);
		}
	}
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
	int count, k, max, min, mxg;
	for(int i = 0; i < source -> offices[source_office_index].packages_count; i++){
		mxg = source -> offices[source_office_index].packages[i].weight;
		min = target -> offices[target_office_index].min_weight;
		max = target -> offices[target_office_index].max_weight;
		if((min <= mxg) && (mxg <= max)) {
			count = target -> offices[target_office_index].packages_count;
			target -> offices[target_office_index].packages = realloc(target -> offices[target_office_index].packages, sizeof(package) * (count + 1));
			target -> offices[target_office_index].packages[count] = source -> offices[source_office_index].packages[i];
			count = source -> offices[source_office_index].packages_count;
			k = i;
			while(k < count - 1){
				package temp = source -> offices[source_office_index].packages[k];
				source -> offices[source_office_index].packages[k] = source -> offices[source_office_index].packages[k + 1];
				source -> offices[source_office_index].packages[k + 1]=temp;
				k++;
			}
			source -> offices[source_office_index].packages = realloc(source -> offices[source_office_index].packages, sizeof(package) * (count - 1));
			target -> offices[target_office_index].packages_count++;
			source -> offices[source_office_index].packages_count--;
			i--;
		}
	}
}

town town_with_most_packages(town* towns, int towns_count) {
	int max = -1, sum, r;
	while(--towns_count > -1) {
		sum = 0;
		for(int i = 0; i < towns[towns_count].offices_count; i++){
			sum += towns[towns_count].offices[i].packages_count;
		}
		if(sum > max) {max = sum; r = towns_count;}
	}
	return towns[r];
}

town* find_town(town* towns, int towns_count, char* name) {
	int i;
	while(--towns_count > -1) {
		if(strcmp(name, towns[towns_count].name)==0) i = towns_count;
	}
	return towns + i;
}

int main() {
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}

//----------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
	char* data;
};

struct sentence {
	struct word* data;
	int word_count;//denotes number of words in a sentence
};

struct paragraph {
	struct sentence* data  ;
	int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
	struct paragraph* data;
	int paragraph_count;//denotes number of paragraphs in a document
};

typedef struct word word;
typedef struct sentence sentence;
typedef struct paragraph paragraph;
typedef struct document document;

void add_char(word* _word, char character) {
	static int size;
	if (_word -> data == NULL){
		_word -> data = (char*)malloc(0);
		size = 2;
	}
	_word -> data = (char*)realloc(_word -> data, size * sizeof(char));
	_word -> data[size - 2] = character;
	_word -> data[size - 1] = 0;
	size++;
}

void add_word(sentence* _sentence, word* _word) {
	if (_sentence -> data == NULL) {
		_sentence -> data = (word*)malloc(0);
		_sentence -> word_count = 0;
	}
	_sentence -> word_count++;
	_sentence -> data = (word*)realloc(_sentence -> data, _sentence -> word_count * sizeof(word));
	_sentence -> data[_sentence -> word_count - 1] = *_word;
	_word -> data = NULL;
}

void add_sentence(paragraph* _paragraph, sentence* _sentence) {
	if (_paragraph -> data == NULL) {
		_paragraph -> data = (sentence*)malloc(0);
		_paragraph -> sentence_count = 0;
	}
	_paragraph -> sentence_count++;
	_paragraph -> data = (sentence*)realloc(_paragraph -> data, _paragraph -> sentence_count * sizeof(sentence));
	_paragraph -> data[_paragraph -> sentence_count - 1] = *_sentence;
	_sentence -> data = NULL;
}

void add_paragraph(document* _document, paragraph* _paragraph) {
	if (_document -> data == NULL) {
		_document -> data = (paragraph*)malloc(0);
		_document -> paragraph_count = 0;
	}
	_document -> paragraph_count++;
	_document -> data = (paragraph*)realloc(_document -> data, _document -> paragraph_count * sizeof(paragraph));
	_document -> data[_document -> paragraph_count - 1] = *_paragraph;
	_paragraph -> data = NULL;
}

struct document get_document(char* text) {
	document _document;
	paragraph _paragraph;
	sentence _sentence;
	word _word;
	_document.data = NULL;
	_paragraph.data = NULL;
	_sentence.data = NULL;
	_word.data = NULL;
	for (unsigned int i = 0; i <= strlen(text); i++){
		switch (text[i])
		{
		case ' ':
			add_word(&_sentence, &_word);
			break;
		case '.':
			add_word(&_sentence, &_word);
			add_sentence(&_paragraph, &_sentence);
			break;
		case '\n':
		case '\0':
			add_paragraph(&_document, &_paragraph);
			break;
		default:
			add_char(&_word, text[i]);
			break;
		}
	}
	return _document;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
	return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
	return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k){
	return Doc.data[k - 1];
}

//----------

/*
I might eventually get around to composing a good C implementation for that O[1] chess knights moves query task and pay close attention to the min(height, width) == 2, 3 special edge cases or whatever as well as general uh close cases and uh... it might be strongest here to literally explicitly enumerate finite cases for when the 2 dudes are uh sufficiently close the starting point and target point etc. etc. just finite enumeration of those topical relevant cases in terms of the uh Deltas and effective buffers surrounding those uh 2 dudes and then uh also more generally just for the general formulaic O[1] reply is sharp for like Trading firms.
*/