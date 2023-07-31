
# Zorunlu Kisim
- Zorunlu kisimin bize temel beceri ve bilgi konusunda gelistirmeye calistigini dusunuyorum. Cunku libft'yi iyi sekilde anlamaya calismak ve hizli gecmemek siradaki projeleri anlamamda cok isime yaradi.
- Asagidaki notlar projeyi tamamlarken merak ettigim ve cevabini aradigim sorulardan olusuyor. Butunuyle libft vermenizi saglayacak notlar degil.

## Bir char nasil bir integer'a donusturulur?
Diyelim ki elimizde '5' karakteri var. Bu karakteri integer'a donusturmek icin yapmamiz gereken tek sey '0' karakterinden cikartmaktir (bu cikartma isleminde karakterlerin decimal karsiliklari arasinda yapilmaktadir). Cikan sonuc ise integer olarak tutulabilmektedir ve bu bize istedigimiz integer sonucu vermektedir.

Ornek: 
```c
('5' - '0') => (53 - 48) => 5
```
Bu işlem, '0' karakteri ile istediğimiz rakam karakteri arasındaki farkı bulmamıza olanak tanır ve sonuç olarak karakteri temsil eden sayısal değeri elde ederiz. Örneğin '9' karakteri için 53 - 48 = 5 olur ve bu şekilde '5' karakterini integer türüne dönüştürmüş oluruz.

## Malloc Nedir ve Nasil Calisir?

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int size = 5;

    // 5 tane int türünde bellek alanı tahsisi yap
    ptr = (int *)malloc(size * sizeof(int));

    if (ptr == NULL) {
        printf("Bellek tahsisi yapilamadi.\n");
        return 1;
    }

    // Bellekte tahsis edilen alanı kullanabilirsiniz

    // Bellek alanını serbest birak
    free(ptr);

    return 0;
}
```
Yukarıdaki örnek, `malloc()` işlevini kullanarak 5  `int` veri türü için bellek alanı ayırır. Bellek alanı başarıyla tahsis edildikten sonra, bu alanı kullanabilirsiniz. Belleği kullanımınız tamamlandığında, `free()` işlevini kullanarak tahsis edilen bellek alanını serbest bırakmanız önemlidir. Bellek alanını serbest bırakmazsanız, programınız hafıza sızıntısı (memory leak) ile karşı karşıya kalabilir, yani tahsis edilen bellek alanınız program sonlanana kadar hafızada kalabilir.

Arkaplanda, `malloc()` işlevi çalışma zamanında işletim sistemi tarafından sağlanan bellek havuzundan uygun miktarda bellek alanı talep eder. Bu bellek havuzu, genellikle programın heap alanı olarak adlandırılan bellek bölgesinde yer alır. `malloc()` işlevi bu bellek havuzundan belirtilen boyut kadar bellek alanı talep eder ve bu alanın başlangıç adresini gösteren bir işaretçi döndürür. Eğer talep edilen bellek alanı mevcut değilse veya yeterli boş bellek yoksa, `malloc()` işlevi `NULL` işaretçisi döndürerek bellek tahsisi başarısız olduğunu belirtir.

Belleği kullanımınız tamamlandığında, `free()` işlevini kullanarak işaretçi ile gösterilen bellek alanını serbest bırakmanız gerekir. `free()` işlevi, bellek alanını programın heap alanında geri verir, böylece başka amaçlar için kullanılabilir hale gelir.
## Isaretci/Adres Aritmetigi nedir? (dst + i)
Adres aritmetiği, işaretçi türü değişkenlerle gerçekleştirilir. İşaretçi, bellekte bir verinin yerini işaret eden bir değişkendir. Bellek adresi tamsayılar gibi düşünülebilir ve işaretçi bu adresleri saklayarak ve manipüle ederek bellek üzerinde gezinmeyi sağlar.

C dilinde adres aritmetiği için kullanılan bazı operatörler şunlardır:

1.  '&' (Ampersand) operatörü: Bu operatör, bir değişkenin bellek adresini elde etmek için kullanılır. Örneğin: `int x = 10; int *ptr = &x;` ptr, x'in bellek adresini tutar.
    
2.  '*' (Asterisk) operatörü: Bu operatör, bir işaretçinin gösterdiği adresteki değeri elde etmek için kullanılır. Örneğin: `int value = *ptr;` value, ptr'nin gösterdiği bellek adresindeki değeri alır.
    
3.  İşaretçi aritmetiği: İşaretçiler, tamsayılarla (integer) aritmetik işlemler gerçekleştirebilir. Bu işlemler, işaretçinin gösterdiği bellek adresini değiştirerek bellek üzerinde gezinmeyi sağlar. Örneğin: `ptr++;` işlemi, ptr'nin gösterdiği bellek adresini bir tamsayı büyütür, böylece bir sonraki bellek hücresine işaret eder.
    
4.  Dizi indeksleme: Diziler, bellekte ardışık hücrelerde depolanan veri koleksiyonlarıdır. Bir diziye işaretçi aritmetiği kullanarak erişilebilirsiniz. Örneğin: `int arr[] = {1, 2, 3}; int *ptr = arr;` ile ptr, dizinin ilk elemanının adresini tutar. `ptr[1]` ifadesi, ikinci elemana erişmeyi sağlar.
    

Örnek bir adres aritmetiği kullanımı:
```c
int arr[] = {10, 20, 30, 40};
int *ptr = arr; // ptr, dizinin ilk elemanının adresini alır

// İkinci elemanin yazdirilamsi
printf("Ikinci eleman: %d\n", *(ptr + 1)); // 20

// Dördüncü elemanın yazdirilmasi
printf("Dorduncu eleman: %d\n", *(ptr + 3)); // 40` 
```
Adres aritmetiği, bellek üzerinde veri manipülasyonu ve veri yapılarının etkin bir şekilde kullanılmasını sağlar. Ancak, dikkatli kullanılmazsa hatalara ve güvenlik açıklarına yol açabileceği için dikkatli olmak önemlidir.

### Isaretci aritmetiginde adres her zaman 1 mi artar?
Her hücre, genellikle bir byte veya daha büyük bir veri parçasını temsil eder. İşaretçi, işaret ettiği hücrenin veri türüne göre ilerler ve işaret ettiği hücrenin boyutuna göre adres aritmetiği yapar.

Işaretçi aritmetiği yaparken işaretçi, işaret ettiği bellek hücresinin boyutunu dikkate alır. Bu nedenle işaretçi bir tamsayı artışı yaparken, hafızada bir tam sayı değeri kadar öteler.

Örnek olarak, bir `int` tipinde işaretçi düşünelim. `int` genellikle 4 byte (32 bit) büyüklüğünde olduğunu varsayalım. Bu durumda işaretçi bir tam sayı artışı yaptığında, işaret ettiği bellek hücresinin adresi, 4 byte ilerleyecektir.
```c
int arr[] = {10, 20, 30, 40};
int *ptr = arr;

ptr = ptr + 1;

printf("Ikinci eleman: %d\n", *ptr);
```
Burada `ptr = ptr + 1;` ifadesi, işaretçinin gösterdiği bellek adresini 4 byte (int'in boyutu) artırır. Sonuç olarak, `ptr`, artık dizinin ikinci elemanını işaret eder.
## Str fonksiyonlar ile mem fonksiyonlar arasindaki fark nedir?
C dilinde, `mem` fonksiyonları ve `str` fonksiyonları, bellek manipülasyonu ve karakter dizisi (string) işlemleri için kullanılan iki farklı kategoride işlevlerdir. İşte bu iki fonksiyon kategorisi arasındaki farklar:

1.  `mem` Fonksiyonları:
    
    -   `mem` fonksiyonları, bellek manipülasyonu için kullanılır. Bellek manipülasyonu, bellek bloklarını kopyalama, karşılaştırma ve doldurma gibi işlemleri içerir.
    -   Bu fonksiyonlar, işaretçilerle çalışır ve genellikle bellek blokları üzerinde byte bazında işlem yaparlar.
    -   `memcpy`, `memmove`, `memcmp`, `memset` gibi `mem` fonksiyonları bu kategoriye örnek olarak verilebilir.
    -   Bellek işlemleri, karakter dizisi olmayan her türlü veri kopyalama, karşılaştırma veya işleme için kullanılabilir.
2.  `str` Fonksiyonları:
    
    -   `str` fonksiyonları, karakter dizileri (string) ile çalışmak için kullanılır. Karakter dizileri, bir dizi karakterin sonlandırıcı karakter (`'\0'` veya NULL karakter) ile bitirildiği veri yapılarıdır.
    -   Bu fonksiyonlar, karakter dizileri üzerinde işlem yapar ve sık kullanılan string manipülasyon işlemleri için optimize edilmiştir.
    -   `strcpy`, `strcmp`, `strlen`, `strcat` gibi `str` fonksiyonları bu kategoriye örnek olarak verilebilir.
    -   Karakter dizileri üzerinde yapılan işlemler, karakter dizilerinin sıfır ile sonlandırılmasına uygun şekilde gerçekleştirilir.

## File Descriptor (fd) nedir?
"file descriptor" (dosya tanımlayıcısı), dosyalara veya diğer giriş/çıkış kaynaklarına erişmek için kullanılan bir tamsayı değeridir. Dosya tanımlayıcısı, işletim sistemi tarafından oluşturulan bir işaretçi gibidir,

Dosya tanımlayıcıları, işletim sisteminde açık olan her dosya için benzersiz bir numaralandırmaya sahiptir. Örneğin, UNIX ve Linux sistemlerinde, 0, 1 ve 2 numaralı dosya tanımlayıcıları özel olarak aşağıdaki şekilde atanır:

-   0: Standart giriş (stdin) - Klavyeden okuma için kullanılır.
-   1: Standart çıkış (stdout) - Ekran yazdırma için kullanılır.
-   2: Standart hata (stderr) - Hata mesajlarını göndermek için kullanılır.

Ayrıca, 3 ve sonraki numaralar, açık olan diğer dosyalar için atanır. Bu dosya tanımlayıcıları, `open()` veya `fopen()` gibi dosya açma işlevleri kullanılarak elde edilir. Dosya tanımlayıcıları, `int` türünden değişkenlerde saklanır.

## Fd icin open fonksiyonu nasil kullanilir?
Fonksiyonun prototipi şu şekildedir:
```c
int open(const char *path, int flags, mode_t mode);` 
```
Burada, `path` parametresi açılacak dosyanın yolu ve adını içeren bir karakter dizisidir. `flags` parametresi açma modunu belirlemek için kullanılır ve hangi türde dosya erişimi yapılacağını belirtir. `mode` parametresi ise yeni bir dosya oluşturulduğunda izinlerin belirlenmesi için kullanılır (bu parametre sadece dosya oluşturulduğunda önemlidir).

`open()` işlevi, bir dosya tanımlayıcısı (file descriptor) döndürür. Dosya tanımlayıcısı, dosyaya erişim ve dosya üzerinde işlem yapmak için kullanılır. Eğer işlem başarısız olursa, -1 değeri döndürür.

---
 **en sık kullanılan `flags` parametreleri ve açıklamaları:**

1.  `O_RDONLY`: Dosyayı sadece okuma modunda açar. Dosyanın içeriği değiştirilemez, sadece okunabilir.
    
2.  `O_WRONLY`: Dosyayı sadece yazma modunda açar. Dosyanın içeriği okunamaz, sadece değiştirilebilir.
    
3.  `O_RDWR`: Dosyayı hem okuma hem de yazma modunda açar. Dosya içeriğini okuyabilir ve değiştirebilirsiniz.
    
4.  `O_CREAT`: Eğer dosya yoksa, yeni bir dosya oluşturur. Bu bayrak, dosya açma işleminin yeni bir dosya oluşturma işlemi için kullanılacağını belirtir.
    
5.  `O_TRUNC`: Dosya varsa, içeriğini temizler (sıfırlar). Dosyayı açarken içeriği silmek ve dosyayı boşaltmak için kullanılır.
    
6.  `O_APPEND`: Dosya varsa, dosyanın sonuna ekler. Yani, her yazma işlemi dosyanın sonuna eklenir, varolan içeriği değiştirmez.
    
7.  `O_EXCL`: Dosya varsa, hata döndürür. Bu bayrak, `O_CREAT` bayrağıyla birlikte kullanılır ve eğer dosya zaten varsa hata döndürür.
    
8.  `O_TRUNC | O_CREAT`: Eğer dosya varsa içeriğini siler, eğer dosya yoksa yeni bir dosya oluşturur. Bu bayrak, dosya içeriğini sıfırlayarak mevcut dosyayı kullanmak için kullanılır.

```c
#include <fcntl.h>  
#include <unistd.h>  
int  main() { 
	int fd; 
// Dosyayı yazma modunda (write-only) aç 
	fd = open("example.txt", O_WRONLY); 
	if (fd == -1) { 
		perror("Dosya acilamadi"); 
		return  1; 
	} 
// Dosyayı kapat 
	close(fd); 
	return  0; 
	}
```
## Typedef Nedir?

"typedef" C dilinde bir anahtar kelimedir ve bir türden yeni bir tür adı tanımlar. Örneğin, aşağıdaki kod parçacığı "unsigned long" türüne "ul" adını verir:

```c
typedef unsigned long ul;
```

Daha sonra, "ul" türünü kullanarak değişkenler tanımlayabilirsiniz:

```c
ul sayi1, sayi2, toplam;
```

Bu, yazımı daha kolay hale getirir ve kodun anlaşılırlığını artırır.

## Size\_t Nedir?

-  Bu veri tipi, genellikle bellekteki bir dizinin veya bir yapının boyutunu ifade etmek için kullanılır. 
- Daha basitce anlatmak gerekirse, "size_t" veri tipi ozel bir veri tipi degildir basitce bir integer typedef'idir
	- 32 bit sistem icin unsigned int typedefidir
	- 64bit sistemlerde unsigned long long typedef'idir. 

**Neden size_t kullaniyoruz?**

- 32bit ya da 64bit, iki sistemde de en fazla limite sahip int turlerinin typedef'ine donuserek kendi limitini asabilen bir boyut olamayacagini garanti eder.
- Herhangi bir nesnenin boyutu negatif olamayacagi icin, programin daha guvenli olmasi icin negatif almaz(unsigned).
- Okunabilirligi kolaylastirir, kodu yazan kisi disinda okuyan birisi size_t tipindeki degiskende bir boyut tutulacagini veya tutuldugunu kolayca anlayabilir.

```c
size_t size; // size değişkeni, bir nesnenin boyutunu ifade eden bir tamsayıdır
```

## Const Nedir?

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

### while (--n) Dongusu Nasil Calisir?

Klasik bir while dongusu, kosulu saglanamadigi zaman duran bir dongudur. Bu (--n) kosulu ise normalde dongunun icinde yaptigimiz iterasyonu (*iterasyon: degiskenleri artirip azaltmak icin kullandigimiz kisayollar n-- n++ vb*) kosulun icine tasimistir. Bu noktada kosul n degiskeni 0 degerine ulasana kadar false deger dondurmeyecektir. Yani iterasyonlarla kurdugumuz kosullarin asil mantigi degiskenin 0'a dusene kadar dongunun calismasini saglamaktir. 
*- Bu noktada lutfen --n ve n-- iterasyonlarinin farkini unutmayin ve hesaplamalarinizi ona gore yapin.*

Örneğin:

```c
int n = 5;
while (--n) {
    printf("%d\n", n);
}
```

Bu örnekte, "while(--n)" ifadesi, "n" değişkeninin değerinin sıfıra ulaşana kadar döngüyü sürdürür ve bu nedenle, döngü 4 kez çalışır. Bu döngünün çalışma sırasında, "n" değişkeninin değeri sırasıyla 4, 3, 2 ve 1 olur ve döngü sona erdiğinde, "n" değişkeninin değeri 0 olur fakat 0 bastirilmaz.

## Cast Nedir ?

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

// dst dizisinin 3. elemanına ulaşmanın farklı bir yolu.
int x = *(dst + 2);
```

Bu örneklerde görüldüğü gibi, dizinin bir elemanına erişmek için "dst\[i]" yapısı kullanılabilir veya "\*(dst + i)" yapısı da kullanılabilir. Bu ikisi arasında bir fark yoktur ve ikisi de aynı şeyi yapar.

Not: Dizinin ilk elemanı "dst\[0]" olarak, ikinci elemanı "dst\[1]" olarak, üçüncü elemanı "dst\[2]" olarak gibi tanımlanır. Bu nedenle, dizinin 3. elemanını "dst\[2]" yapısıyla erişiriz.

### strcpy ve memcpy farkı nedir?

C dilinde "strcpy" ve "memcpy" fonksiyonları, iki dizi arasında veri kopyalama işlemi yapar. Ancak, iki fonksiyon arasında bazı farklılıklar vardır:

* "strcpy" fonksiyonu, bir dizinin içeriğini başka bir diziye kopyalar. Bu fonksiyon, sadece karakter dizileri (string) için kullanılır ve son karaktere ('\0') kadar kopyalar.
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


### is Fonksiyonlarında Neden Int Veri Tipi ile Argüman Alıyoruz?

C dilinde bilgisayar char veri tipini algılamak için dahi karakterlerin integer karşılıklarını hesaplayarak işlem yapar. C dilinde tüm veri tiplerinin integer karşılıkları vardır. Bu da en temel de int veri tipinin olduğunu gösteriyor.

Char veri tipi saklama konusunda sadece temel ascii tablosu ile sınırlıyken int tüm karakterleri saklayabilmektedir. Temel ascii tablosu dışındakiler dahil. Bu yüzden bu fonksiyonlarda int kullanarak var olan tüm karakterlerin argüman olarak girilebilmesini ve kontrol edilebilmesini sağlıyoruz.

### Overlap Nedir?

- yemin ederim buradan anlatmasi cok zor, yuz yuze daha kolay anlatirim.

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

### Bazı fonksiyonlarda değişkenleri nasıl karşılaştırıyoruz?

Örneğin memmove fonksiyonunda if(dst < src) gibi bir if koşulumuz var. Burada aslında dst ve src'nin adreslerinin integer karşılıklarını karşılaştırıyoruz. Eğer dst değişkeninin int adres karşılığı src değişkeninin int adres karşılığından küçükse dst değişkeni bellekte daha önde konumlanmış demektir. Bu koşul da memmove'un overlap'e karşı olan savunmasında yardımcı olacaktır.

### strnstr fonksiyonunda neden i < (len - len\_n) yapıyoruz?

* len-n burada arayacağımız string'in uzunluğunu tutuyor.
* bir string'i bir string'in içinde arıyorsak, aranacak alan uzunluğu (yani len) aranacak string'in uzunluğundan (yani len\_n) daha büyük olmak zorunda.

Örnek:

* Herhangi bir string içinde "Emre" stringini arayacağız. Ama fonksiyona araması için sadece 3 karakterlik bir alan verirsek, "Emre" stringi arama yapılacak string'in en başında olsa bile "Emr" bulup "Emre" bulamayacağı için bize doğru çıktıyı vermez.

### İki boyutlu dize nedir?
- bu soruyu splite gectigimde sormustum. cunku split basitce baktiginizda tek boyutlu bir dizeyi iki boyutlu bir dizeye ceviriyor.

İki boyutluyu açıklamadan önce tek boyutlu dizelerden bahsetmeliyim. Tek boyutlu dizeler aslında her zaman kullandığımız dizi tanımlama şeklimizdir.

Örneğin:

`veri-tipi dizi-ismi [dizinin-boyutu] = "dizinin-kendisi";`

\--> Üstteki örnekte genel olarak kullandığımız dizi tanımlamayı gördük. Bu dizi tanımlamasına tek boyutlu dizi tanımlaması denir.

Şimdi gelelim iki boyutlu dizelere. İki boyutlu dizelerde tek boyutlu dizelerden farklı olarak satır ve sütun konuları için içine giriyor.

Örneğin:

`veri-tipi dizi-ismi [satır-sayısı] [sütun-sayısı] = {satır0-sutun0,satır0-sutun1....};`

`Örnek bir tam sayı dizisi: int dizi[2][3] = {{12,34,22},{11,49,98}};`

Eğer üstteki tam sayı dizisini dizi\[1]\[1] şeklinde yazdırmak isteseydik bize çıkacak olan sonuç dizideki 2. satırın 2.sütunu olacaktır. Yani 49 ve 22 olacaktır.

# Bonus Kisim
- Bonus kisimin, yapi mantigini ve  en cok kullanilan (sanirim) yapi turlerinden biri olan bagli listeyi ogrenmemizi amacladigini dusunuyorum.

### Struct Nedir?

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

Bu değişkene, yapının içindeki değişkenlere ulaşmak için nokta (.) operatörü kullanılır. (Sanirim ayni islev icin "->" operatorunu de kullanabiliyoruz fakat ufak farklar varmis bu farklari tam olarak cozemedim) Örneğin:

```c
s.name = "John";
s.id = 12345;
s.grade = 85.5;
```
## Bağlı Liste Nedir?

Bağlı listeler, birbirine "bağlı" veri yapılarıdır. Bu, bir elemanın bir sonraki elemanı işaret eden bir bağlantı içerdiği anlamına gelir. Bu yapı sayesinde, bir eleman eklenirken veya çıkarılırken, diğer elemanların yerleri değişmez ve sadece eklenen veya çıkarılan elemana bağlı olarak bağlantılar güncellenir.

Bağlı listeler, C dilinde "t_list" yapısı kullanılarak tanımlanabilir. Bu yapı, bir "content" öğesi ve bir "next" öğesi içerir. "content" öğesi, elemanın içeriğini tutar ve "next" öğesi, bir sonraki elemana işaret eden bir bağlantı içerir.

Bağlı listeler, çeşitli veri yapılarının oluşturulmasında kullanılabilir. Örneğin, bir kuyruk (queue) veya bir yığın (stack) gibi veri yapıları oluşturulabilir. Ayrıca, verilerin sıralı bir şekilde saklanması ve aranması gibi işlemlerde de kullanılabilir.

### Bonus Kısım da Libft'ye Eklenen Struct Nedir?

typedef, C dilinde bir tür tanımlamayı yapmanızı sağlar. Örneğin, libft.h dosyasına eklediğimiz kod bloğunda "t_list" olarak bir tür tanımlanmıştır ve bu tür "struct s_list" yapısına eşitlenmiştir. Bu sayede, "t_list" türünü "struct s_list" yerine kullanabilirsiniz.

"t_list" yapısı, içeriği "void \*content" ve bir sonraki yapının adresini tutan "struct s_list *next" gibi iki özelliğe sahiptir. Bu yapı, bir veri yapısı olarak bir bağlı liste oluşturmak için kullanılabilir.

### "->" Operatörü Nedir?

C dilinde, -> işareti bir yapının özelliğine erişmek için kullanılır. Örneğin, aşağıdaki kod bloğunda "ogrenci" adlı bir yapı tanımlanmıştır ve bu yapının "ad" ve "yas" adlı iki özelliği vardır:

```c
struct Ogrenci {
    char *ad;
    int yas;
};

int main(void) {
    struct Ogrenci ogrenci = {"Ali", 20};
    printf("Ad: %s, Yaş: %d\n", ogrenci.ad, ogrenci.yas);
    return 0;
}
```

Bu örnekte, yapının özelliklerine . operatörüyle erişilebilir. Ancak, yapının bir adresine eriştiğinizde -> operatörünü kullanmanız gerekir. Örneğin:

```c
struct Ogrenci *ogrenci_ptr = &ogrenci;
printf("Ad: %s, Yaş: %d\n", ogrenci_ptr->ad, ogrenci_ptr->yas);
```

Bu kod bloğunda, ogrenci_ptr adlı bir yapı adresi oluşturulur ve bu adresin içindeki "ad" ve "yas" özelliklerine -> operatörüyle erişilir. Bu işaret, ogrenci_ptr adresindeki yapının özelliklerine erişmek için kullanılır ve çıktı olarak aynı sonucu verir.

### Malloc'ta Neden Tür Dönüşümü(Type Casting) Kullanırız?

Malloc fonksiyonu, bellekte yer açmak için kullanılan bir C fonksiyonudur ve void * tipinde bir değer döndürür. Bu, malloc fonksiyonunun hangi türde bir değişken için yer açtığını bilemediğimiz anlamına gelir. Bu nedenle, malloc fonksiyonunun döndürdüğü değerin bir tür belirtilmesi gerekir. Bu tür belirtimi tür dönüşümü ile yapılır. Örneğin:

```c
int *ptr;
ptr = (int *) malloc(sizeof(int));
```

Bu örnekte, malloc fonksiyonu bir int değişkeni için gerekli olan bellek miktarını hesaplar ve bu miktar kadar bellek alanı ayırır. Daha sonra, malloc fonksiyonunun döndürdüğü değer int türüne dönüştürülerek ptr değişkenine atanır.

Not: Tür dönüşümünün kullanılması malloc fonksiyonunun döndürdüğü değerin bir tür belirtilmesini sağlar, ancak bu değerin gerçekten o türden bir değer olup olmadığını doğrulamaz. Bu nedenle, malloc fonksiyonunun döndürdüğü değeri kullanmadan önce mutlaka doğru türden bir değer olduğundan emin olunmalıdır.


### Del fonksiyonu ile nasıl bir linked list elemanı silerim?

del fonksiyonu, bir linked list elemanının içeriğini (content alanını) silmek için kullanılan bir fonksiyondur. Bu fonksiyon, bir void * tipinde bir parametre alır ve içeriği silmek için kullanılır. Örneğin, bir linked listte int türünde değerler tutuluyorsa, del fonksiyonu aşağıdaki gibi olabilir:

```c
void del_int(void *content)
{
free(content);
}
```

Bu fonksiyon, void * tipinde bir değişkeni int türüne dönüştürerek free fonksiyonu ile bellekten siler.

Bu fonksiyonu kullanmak için, ft_lstdelone gibi bir fonksiyonda del fonksiyonunun adresini parametre olarak vermelisiniz. Örneğin:

ft_lstdelone(lst, del_int);

Bu örnekte, lst elemanının içeriği del_int fonksiyonu ile silinir.

### Node nedir?

Bilgisayar biliminde, bir node veri yapısının temel bir birimidir, örneğin bir bağlı liste veya ağaç veri yapısı gibi.

Bağlı liste, her elemanın ayrı bir nesne olarak adlandırılan bir node olduğu lineer bir veri yapısıdır. Her node'un iki alanı vardır: bir elemanı depolamak için bir veri alanı ve bir sonraki node'u gösteren bir sonraki alan. Liste sonundaki son node'un bir sonraki alanı null olarak ayarlanmıştır, bu da listenin sonunu gösterir.

Ağaç veri yapısında, bir node veri depolayan ve bir veya daha fazla çocuk node'a götüren bir referans olan bir nesnedir. Ağaçtaki en üst node root düğüm olarak adlandırılır ve çocukları olmayan düğümler ise leaf düğümler olarak adlandırılır.

Bağlı listelerde ve ağaç veri yapılarında, nodelar veriyi efektif bir şekilde ekleme, silme ve veriye erişim için depolamak ve düzenlemek için kullanılır.

# Makefile
- Makefile ile yaptigimiz islemlerin sebeplerini anlamamiz icin bir kac konuya hakim olmamiz gerekiyor. Bunlarin derleyici asamalari ve statik kutuphane oldugunu dusunuyorum.
## Derleyici Aşamaları
### Adim 1: Preprocess
Bu ilk aşamada, GCC kaynak kodunu (genellikle .c dosyası olarak kaydedilir) alır ve başlık dosyaları (ör. <stdio.h>, <stdlib.h>) dahil olmak üzere yorumları kaldırir, makro adını kodla genişletir ( örneğin #define). 
### Adim 2: Compiler
Bu asamada, kodun her satiri assembly diline cevrilir. Assemly dili, makine diliyle birebir ortusen ingilizce numerik bir dildir. Bu asama da ortaya cikan dosya uzantisi ".s"dir.
### Adim 3: Assembler
Bu asamada assembly kodu direkt olarak makine diline (object code'a) cevrilir. Artik kodumuz bilgisayarin direkt olarak anlayabilecegi ve calistirabilecegi bir duruma gelmis olur. Eger kodumuzun sadece makine diline cevrilmesini istiyorsan gcc -c komutunu kullanabiliriz. Bu asama da ortaya ".o" uzantili dosyalar cikar.
### Adim 4: Linker

Bu asama iki amaca hizmet eder:

- Birden fazla c dosyasini birlikte calistirmak istiyorsaniz bu dosyalari birbirine baglayabilir.
- Kodlarinizda bir kutuphane kullandiysaniz bunlarin ciktisini alip kodlarinizla baglayarak cikti almanizi saglayabilir.

Linker sadece okunabilir ve calistirilabilir olan makine dili (yani objective code) uzerinden baglanti yapabilir. Zaten biz de bu yuzden makefile'imizdaki komutlarla kutuphanemizdeki fonksiyonlarin makine diline cevrilmis hallerini libft.a(statik kutuphane) dosyasinda arsivleyecegiz.

## Statik Kutuphane
Kütüphaneler link aşamasında linker tarafından değerlendirilmektedir. Statik bir kütüphane object modül dosyalarından oluşmaktadır. Gerek .lib, gerekse **.a** dosyaları object modülleri tutan kap gibidir. Yani bir .lib ya da .a dosyasına bir object modül eklenebilir veya çıkarılabilir. Yani statik kütüphanelerde tek bir fonksiyon eklemek ya da çıkartmak diye bir şey yoktur. Bir grup fonksiyonlar bir C dosyasına yazılır, dosya derlenir. **.o** ya da . obj haline getirilmiş dosya statik kütüphaneye eklenir.

Windows sistemlerinde .lib dosyası yaratmak ve içerisine object modül eklemek için lib.exe isimli, UNIX\Linux sistemlerinde ise **ar** isimli utility bu işlemi yapmaktadır. Statik bir kütüphaneye çağrı yapıldığında çağrı isteği derleyici tarafından object modüle yazılır, linker bu fonksiyonu önce projeyi oluşturan diğer object modüllerde sonra statik kütüphanelerde arar. Eğer ilgili fonksiyon statik kütüphanede bulursa linker tarafından bu fonksiyonun içerisinde bulunduğu object modüle statik kütüphane dosyasından alınarak çalıştırılabilir(executable) dosyaya yazılır.

Yani kisaca kodlarimizin derlenmis hallerini yani .o dosyalarini statik kutuphane yani libft.a'da "gcc -c" ve "ar" komutlariyla arsivleriz. Linker'da ihtiyaci olan fonksiyonlari direkt calistirilabilir olarak libft.a'dan ceker ve oylelikle ciktiya dahil eder. gcc -c ve ar komutlarini arastirin ve makefile'i kurcalayarak nasil kullanildiklarina bakin.

## Makefile Icerigi Basit Aciklama

NAME", "FLAG", "SRC" ve "BONUS" değişkenleri, projenin oluşturulmasında kullanılan çeşitli dosya isimlerini depolar.

"SRC" değişkeni proje dizinindeki C dosyalarının (ft_lst ile başlayan dosyalar hariç) listesini içerir, "BONUS" değişkeni ft_lst ile başlayan C dosyalarının listesini içerir ve "OBJ" değişkeni son binary oluşturmak için kullanılan obj dosyalarını içerir.

"$(NAME)" hedefi son binary'nin oluşturulması için kullanılır. "gcc" komutu kaynak dosyaları derlemek ve obj dosyalarını oluşturmak için kullanılır, daha sonra "ar" komutu statik library, libft.a oluşturmak için kullanılır.

"bonus" hedefi "$(NAME)" hedefi ile benzerdir ancak sadece "BONUS" değişkeninde listelenen dosyaları derler.

"clean" hedefi obj dosyalarını silmek için kullanılır.

"fclean" hedefi obj dosyalarını ve son binary'i silmek için kullanılır.

"re" hedefi projeyi yeniden oluşturmak için önce "fclean" hedefini çalıştırarak ve sonra "all" hedefine devam eder.

Son olarak, ".PHONY" satırı "all", "bonus", "clean", "fclean" ve "re" hedeflerinin aynı isimde dosya olmadıklarını ve her zaman çalıştırılması gerektiğini belirtir.





