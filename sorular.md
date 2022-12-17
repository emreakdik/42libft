

# asks

###  Void Veri Tipi Nedir?

C dilinde, "void" veri tipi bir fonksiyonun geri dönüş değeri olmadığını belirtir ve bu nedenle, "void" veri tipinde bir değişken tanımlanamaz. Örneğin:

```c
void x; // Bu satır hata verir, çünkü "void" veri tipinde bir değişken tanımlanamaz
```

"void" veri tipi, yalnızca fonksiyonların geri dönüş değeri olarak kullanılır ve değişkenler için geçerli değildir. Eğer bir değişken için geri dönüş değeri gerekmeyecekse, genellikle "int" veri tipi kullanılır. Örneğin:

```c
int x; // Bu satır geçerlidir ve x değişkeni "int" veri tipinde bir değişkendir
```

Ancak, "void" veri tipinde bir fonksiyonun argüman listesi olabilir ve bu nedenle, "void" veri tipinde bir değişkenin fonksiyonun argümanı olarak geçirilebileceğini unutmayın. Örneğin:

```c
void print_number(void *ptr) { // ptr değişkeni "void" veri tipinde bir değişkendir
    int n = *(int *)ptr;
    printf("%d\n", n);
}

int main() {
    int x = 5;
    print_number(&x); // x değişkeninin adresi "void" tipinde ptr değişkenine geçirilir
    return 0;
}
```



### Size\_t Nedir?

C dilinde, "size\_t" veri tipi bir bellekteki bir nesnenin boyutunu ifade eden bir tamsayıdır. Bu veri tipi, genellikle bellekteki bir dizinin veya bir yapının boyutunu ifade etmek için kullanılır ve çoğu zaman, "unsigned int" veri tipine eşdeğerdir. Örneğin:

```c
size_t size; // size değişkeni, bir nesnenin boyutunu ifade eden bir tamsayıdır
```

"size\_t" veri tipi, genellikle bellek işlemleriyle ilgili fonksiyonlarda kullanılır. Örneğin, "malloc" fonksiyonu, bir nesnenin bellekteki boyutunu ifade etmek için "size\_t" veri tipini kullanır:

```c
#include <stdlib.h>

int main() {
    size_t size = 10;
    int *array = malloc(size * sizeof(int)); // 10 tane int değerini saklayabilecek bir dizi alanı ayırılır
    free(array); // Alınan bellek alanı serbest bırakılır
    return 0;
}
```

İşlenebilecek en büyük nesnenin dahi boyutunu tutabileceği garantidir. Temel olarak izin verilen maksimum boyut, derleyiciye bağlıdır; derleyici 32 bit ise, o zaman unsigned int için basitçe bir typedef'dir (yani takma addır), ancak derleyici 64 bit ise, unsigned long long için bir typedef olacaktır. size\_t veri türü asla negatif değildir.



### Const Nedir?

C dilinde, "_const_" anahtar kelimesi bir değişkenin değerinin değiştirilemeyeceğini belirtir. Bu, bir değişkenin bir kez atandıktan sonra değerinin değiştirilemeyeceği anlamına gelir.&#x20;

Örneğin:

```c
const int x = 5;
x = 10; // Bu satır hata verir, çünkü x değişkeninin değeri değiştirilemez
```

"_const_" anahtar kelimesi, bir değişkenin değerinin değiştirilemeyeceğini garanti eder ve bu, programınızın daha güvenli ve hatasız çalışmasını sağlar. Ayrıca, "const" değişkenler genellikle sabit değerleri temsil eder ve bu nedenle, sabit değerleri "const" değişkenlerle tanımlamanız tavsiye edilir.

```c
const float pi = 3.14159; // pi değişkeni, pi sabitinin değerini temsil eder
```

"_const_" anahtar kelimesi, C dilinin önemli bir özelliğidir ve programlarınızda sıklıkla kullanılır. Değişkenlerin değerlerinin değiştirilememesi, programınızın daha güvenli ve hatasız çalışmasını sağlar ve ayrıca, kodunuzun okunabilirliğini ve anlaşılırlığını artırır.

### while (n--) nedir?

"while(--n)" ifadesi, bir döngüyü sürdürmek için kullanılan bir yapıdır. Bu yapı, belirtilen koşulu sağladığı sürece döngüyü tekrar etmeyi sürdürür. Koşul, "n" değişkeninin değerine göre belirlenir ve bu değişken her döngü adımında bir azaltılır ("n--" ifadesi ile aynı anlama gelir). Bu nedenle, "while(--n)" ifadesi, "n" değişkeninin değeri sıfıra ulaşana kadar döngüyü sürdürecektir. Örneğin:

```c
int n = 5;
while (--n) {
    printf("%d\n", n);
}
```

Bu örnekte, "while(--n)" ifadesi, "n" değişkeninin değerinin sıfıra ulaşana kadar döngüyü sürdürür ve bu nedenle, döngü 4 kez çalışır. Bu döngünün çalışma sırasında, "n" değişkeninin değeri sırasıyla 4, 3, 2 ve 1 olur ve döngü sona erdiğinde, "n" değişkeninin değeri 0 olur.

###  Cast Nedir ? (char \*)

C dilinde "cast" (dönüştürme) işlemi, bir veri türünü başka bir veri türüne dönüştürmek için kullanılır. Örneğin, bir sayının tamsayı türünden ondalık türüne dönüştürülmesi gibi. Dönüştürme işlemi, verinin değerini değiştirmez, sadece verinin türünü değiştirir.

Cast işleminin kullanımı şöyle yapılır:

```c
(veri_turu) veri
```

Örneğin:

```c
int x = 5;
float y = (float) x;
```

Bu kod parçacığında, x değişkeni int türünde ve değeri 5'tir. Daha sonra, x değişkeni float türüne dönüştürülür ve y değişkenine atanır. Bu işlem sonucunda, y değişkeni float türünde ve değeri 5.0 olacaktır.

Cast işleminin dikkatli kullanılması gerekir, çünkü bazen verinin türü değiştirilemez veya verinin değeri anlamsız hale gelebilir. Örneğin, bir ondalık sayıyı tamsayı türüne dönüştürürken, ondalık kısım atılır ve sonuç ona göre oluşacaktır.

### "dst + i" Nedir?

"dst + i" ifadesi, C dilinde bir dizinin bir elemanına erişmek için kullanılabilir. "dst" dizi adıdır ve "i" değişkeni dizinin kaçıncı elemanına erişmek istediğimizi belirtir. Örneğin:

```c
int dst[10];

// dst dizisinin 3. elemanına erişmek için
int x = dst[2];

// dst dizisinin 3. elemanına değer atamak için
dst[2] = 5;

// dst dizisinin 3. elemanına aynı zamanda
int x = *(dst + 2);
```

Bu örneklerde görüldüğü gibi, dizinin bir elemanına erişmek için "dst\[i]" yapısı kullanılabilir veya "\*(dst + i)" yapısı da kullanılabilir. Bu ikisi arasında bir fark yoktur ve ikisi de aynı şeyi yapar.

Not: Dizinin ilk elemanı "dst\[0]" olarak, ikinci elemanı "dst\[1]" olarak, üçüncü elemanı "dst\[2]" olarak gibi tanımlanır. Bu nedenle, dizinin 3. elemanını "dst\[2]" yapısıyla erişiriz.

### strcpy ve memcpy farkı nedir?

C dilinde "strcpy" ve "memcpy" fonksiyonları, iki dizi arasında veri kopyalama işlemi yapar. Ancak, iki fonksiyon arasında bazı farklılıklar vardır:

* "strcpy" fonksiyonu, bir dizinin içeriğini başka bir diziye kopyalar. Bu fonksiyon, sadece karakter dizileri (string) için kullanılır ve son karakterin ('\0') yerine kadar kopyalar.
* "memcpy" fonksiyonu ise, bir dizinin belirli bir bölümünü başka bir diziye kopyalar. Bu fonksiyon, tüm veri türleri için kullanılabilir ve belirtilen uzunlukta veri kopyalar.

Örnek olarak:

```c
char str1[10] = "hello";
char str2[10];

// str1 dizisinin içeriğini str2 dizisine kopyalar
strcpy(str2, str1);

int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5];

// arr1 dizisinin 2. ve 3. elemanlarını arr2 dizisine kopyalar
memcpy(arr2, &arr1[1], sizeof(int) * 2);
```

Bu örneklerde görüldüğü gibi, "strcpy" fonksiyonu sadece karakter dizileri için kullanılır ve son karaktere kadar kopyalar, iken "memcpy" fonksiyonu tüm veri türleri için kullanılabilir ve belirtilen uzunlukta veri kopyalar.

###  Typedef Nedir?

"typedef" C dilinde bir anahtar kelimedir ve bir türden yeni bir tür adı tanımlar. Örneğin, aşağıdaki kod parçacığı "unsigned long" türüne "ul" adını verir:

```c
typedef unsigned long ul;
```

Daha sonra, "ul" türünü kullanarak değişkenler tanımlayabilirsiniz:

```c
ul sayi1, sayi2, toplam;
```

Bu, yazımı daha kolay hale getirir ve kodun anlaşılırlığını artırır.

###  is Fonksiyonlarında Neden Int Veri Tipi ile Argüman Alıyoruz?

C dilinde bilgisayar char veri tipini algılamak için dahi karakterlerin integer karşılıklarını hesaplayarak işlem yapar. C dilinde tüm veri tiplerinin integer karşılıkları vardır. Bu da en temel de int veri tipinin olduğunu gösteriyor.

Char veri tipi saklama konusunda sadece temel ascii tablosu ile sınırlıyken int tüm karakterleri saklayabilmektedir. Temel ascii tablosu dışındakiler dahil. Bu yüzden bu fonksiyonlarda int kullanarak var olan tüm karakterlerin argüman olarak girilebilmesini ve kontrol edilebilmesini sağlıyoruz.

###  Overlap Nedir?

Memcpy gibi bir fonksiyonda kopyalanacak olan src'nin kopyalama esnasında bozulması ve sıradaki kopyalayacağı karakterlerin değişmesidir. Bunun yüzünden kopyalama doğru gerçekleşmez.

Overlap olması için src'nin bellekte dst değişkeninden önce konumlanmış olması gerekmektedir. Overlap _sadece_ hem src'nin hem de  dst'nin aynı string'in içeriğinden oluştuğu zaman olmaz. Aynı zamanda src ve dst'nin peş peşe oluşmuş bellek bloklarında barınmasıyla gerçekleşebilir.

Örnek:

```c
char src[] = "Emre Akdik";
char dest[100];

ft_memcpy(&src[2], src, 9);
printf("%s", dest);
```

* Bu örnekte src ve dst aynı string içinden oluşmuştur ve src'nin başlangıcı dst'nin başlangıcından daha önce olduğu için src'nin bellek bloğu dst'nin bellek bloğundan öndedir. Bu durumda overlap mümkündür. src'miz "Emre Akdik"dir, dest ise "re Akdik" dir.
* Dest ilk iki indeksin kopyalanması ile "em akdik"e dönüşür fakat aynı zamanda src'de "Emem Akdik"e dönüşür. İşte burada kopyalama esnasında karakterler üst üste binmiş olur.
* src'den kopyalama için alınacak sıradaki iki indeks re'den em'e dönüşmüş oldu ve dest'e "re" eklemesi gerekirken kopyalama esnasında src bozulduğu için "em" ekleyecek. Artık dest "ememkdik" olmuştur.
* Bundan sonraki tüm adımlarda her kopyalama işlemi yapıldığında sıradaki kopyalama için alınacak karakterleri değiştirecek ve istenilen sonucu alamayacağız.&#x20;
* Ana mantık src'nin dst'den önce olması ve dst'ye src'den kopyalama yaparken dst ve src'nin üst üste binip srcnin bozulmasıdır. Çıktıyı örneği derleyerek kontrol edebilirsiniz.

#### Bazı fonksiyonlarda değişkenleri nasıl karşılaştırıyoruz?

Örneğin memmove fonksiyonunda if(dst < src) gibi bir if koşulumuz var. Burada aslında dst ve src'nin adreslerinin integer karşılıklarını karşılaştırıyoruz. Eğer dst değişkeninin int adres karşılığı src değişkeninin int adres karşılığından küçükse dst değişkeni bellekte daha önde konumlanmış demektir. Bu koşul da memmove'un overlap'e karşı olan savunmasında yardımcı olacaktır.

#### strnstr fonksiyonunda neden i < (len - len\_n) yapıyoruz?

* len-n burada arayacağımız string'in uzunluğunu tutuyor.
* bir string'i bir string'in içinde arıyorsak, aranacak alan uzunluğu (yani len) aranacak string'in uzunluğundan (yani len\_n) daha büyük olmak zorunda.

Örnek:

* Herhangi bir string içinde "Emre" stringini arayacağız. Ama fonksiyona araması için sadece 3 karakterlik bir alan verirsek, "Emre" stringi arama yapılacak string'in en başında olsa bile "Emr" bulup "Emre" bulamayacağı için bize doğru çıktıyı vermez.

#### İki boyutlu dize nedir?

İki boyutluyu açıklamadan önce tek boyutlu dizelerden bahsetmeliyim. Tek boyutlu dizeler aslında her zaman kullandığımız dizi tanımlama şeklimizdir.

Örneğin:

`veri-tipi dizi-ismi [dizinin-boyutu] = "dizinin-kendisi";`

\--> Üstteki örnekte genel olarak kullandığımız dizi tanımlamayı gördük. Bu dizi tanımlamasına tek boyutlu dizi tanımlaması denir.

Şimdi gelelim iki boyutlu dizelere. İki boyutlu dizelerde tek boyutlu dizelerden farklı olarak satır ve sütun konuları için içine giriyor.

Örneğin:

`veri-tipi dizi-ismi [satır-sayısı] [sütun-sayısı] = {satır0-sutun0,satır0-sutun1....};`

`Örnek bir tam sayı dizisi: int dizi[2][3] = {{12,34,22},{11,49,98}};`

Eğer üstteki tam sayı dizisini dizi\[1]\[1] şeklinde yazdırmak isteseydik bize çıkacak olan sonuç dizideki 2. satırın 2.sütunu olacaktır. Yani 49 ve 22 olacaktır.

![](<.gitbook/assets/Screenshot from 2022-12-16 01-53-55.png>)



### Nasıl Liste Oluşturulur? Struct Nedir?

C dilinde yapı/struct, veri yapılarının bir koleksiyonudur. Yapılar, birbirleriyle ilişkili verilerin bir arada saklanması için kullanılır. Yapılar, bir dizi değişkenin bir arada saklanmasını sağlar ve bu değişkenlerin her birine özel bir ad verilebilir. Örneğin, bir öğrenci yapısı oluşturarak, bir öğrencinin adını, numarasını ve notlarını saklayabilirsiniz.

Yapıları tanımlamak için "struct" anahtar kelimesi kullanılır. Örneğin, bir öğrenci yapısı tanımlamak için aşağıdaki gibi bir kod bloğu kullanabilirsiniz:

```c
struct student {
    char name[50];
    int id;
    float grade;
};
```

Bu yapıyı kullanmak için, yapı türünden bir değişken oluşturmanız gerekir. Örneğin:

```c
struct student s;
```

Bu değişkene, yapının içindeki değişkenlere ulaşmak için nokta (.) operatörü kullanılır. Örneğin:

```c
s.name = "John";
s.id = 12345;
s.grade = 85.5;
```
