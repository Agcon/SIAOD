# include <limits.h>
# include <string.h>
# include <stdio.h>

/**
* 1)
Дан текст. Найти индекс последнего вхождения заданной подстроки в текст,
с указанием позиции места размещения подстроки в тексте.
 Метод поиска: Эффективный Бойера-Мура
*/
/*
2) Дан текст, содержащий адреса сайтов. Заменить в тексте в доменных имена России ru на рус.
*/

# define NO_OF_CHARS 256

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// The preprocessing function for Boyer Moore's bad character heuristic
void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Fill the actual value of last occurrence of a character
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void search(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0; // s is shift of the pattern with respect to text
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            printf("\n pattern occurs at shift = %d", s);

            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

        }

        else
            s += max(1, j - badchar[txt[s + j]]);
    }
}

/* Driver program to test above funtion */
int main()
{
    char txt[] = "ABAAABCD";
    char pat[] = "ABC";
    search(txt, pat);
   string text;
    string str1 = ".ru";
    string str2 = ".рус";
    long sPos;

    cout<<"Введите текст: " << endl;
    getline(cin,text);
    cin.ignore();

    while((sPos = text.find(str1,0)) != string::npos)
        text.replace(sPos,str1.length(),str2);
    cout<<"Обработанный тест:" << endl << text <<endl;
    return 0;
}
