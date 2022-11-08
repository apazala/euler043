#include <iostream>
#include <cinttypes>

#define LEN 10

#define swap(a, b) aux = a; a = b; b = aux

using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17};
int nprimes = sizeof(primes)/sizeof(primes[0]);

bool check(char *pandig)
{ 
    bool pass = true;
    for(int i = 0, start = 2; i < nprimes && pass; i++, start++){
        int n = 0;
        for(int j = start, end = start+3; j < end; j++){
            n = 10*n + (pandig[j]-'0');
        }
        pass = (n%primes[i])==0;
    }

    return pass;
}

int main(int argc, char **argv)
{
	char lexword[LEN+1] = "1023456789";
	char aux;
	
    int64_t sum = 0;
	for(;;){

        if(check(lexword-1)) //1-based array
        {
            int64_t n = lexword[0]-'0';
            for(int kk = 1; kk < 10; kk++){
                n*=10;
                n+=lexword[kk]-'0';
            }
            cout << lexword << " ||| " << n << endl;
            sum += n;
        }

		int i = LEN - 2;
		while (i >= 0 &&lexword[i] >= lexword[i+1])
			i--;
        if(i< 0)
            break;
        
		int j = LEN - 1;
		while (lexword[j] <= lexword[i])
			j--;
		swap(lexword[i], lexword[j]);
		for(char *suffwd = lexword + i + 1, *sufbwd = lexword + LEN -1; suffwd < sufbwd; suffwd++, sufbwd--)
		{
			swap(*sufbwd, *suffwd);
		}		
	}
	
    cout << sum << endl;
	
    return 0;
}