#include <stdio.h>
#include <string.h>

/* ---- Kendi ft_strcapitalize.c dosyandaki fonksiyonlar burada varsayılıyor ---- */
/* Bu dosyayı derlerken kendi ft_strcapitalize.c'ni de linklemen gerekiyor,     */
/* ya da bu test dosyasını doğrudan kendi .c dosyanın altına ekleyebilirsin.   */

char	*ft_strcapitalize(char *str);

/* ---- Test yardımcı fonksiyonu ---- */
int	run_test(char *input, char *expected)
{
	char	buf[256];
	char	*result;

	strcpy(buf, input);
	result = ft_strcapitalize(buf);
	if (strcmp(result, expected) == 0)
	{
		printf("[OK]   \"%s\" -> \"%s\"\n", input, result);
		return (1);
	}
	else
	{
		printf("[FAIL] \"%s\" -> \"%s\" (beklenen: \"%s\")\n",
			input, result, expected);
		return (0);
	}
}

int	main(void)
{
	int	total;
	int	passed;

	total = 0;
	passed = 0;

	/* --- Temel kelime testleri --- */
	passed += run_test("hello", "Hello");
	total++;
	passed += run_test("hello world", "Hello World");
	total++;
	passed += run_test("HELLO WORLD", "Hello World");
	total++;
	passed += run_test("HeLLo WoRLD", "Hello World");
	total++;

	/* --- Boşluk / ayırıcı çeşitleri --- */
	passed += run_test("hello-world", "Hello-World");
	total++;
	passed += run_test("hello_world", "Hello_World");
	total++;
	passed += run_test("hello+world", "Hello+World");
	total++;
	passed += run_test("hello;world", "Hello;World");
	total++;
	passed += run_test("hello,world", "Hello,World");
	total++;
	passed += run_test("hello.world", "Hello.World");
	total++;

	/* --- Rakamla birleşik kelimeler --- */
	passed += run_test("42world", "42world");
	total++;
	passed += run_test("world42", "World42");
	total++;
	passed += run_test("42", "42");
	total++;
	passed += run_test("4a2b", "4a2b");
	total++;

	/* --- Ardışık ayırıcılar --- */
	passed += run_test("hello  world", "Hello  World");
	total++;
	passed += run_test("hello---world", "Hello---World");
	total++;
	passed += run_test("hello!!world", "Hello!!World");
	total++;

	/* --- Diğer tüm non-alphanumeric ayırıcı türleri --- */
	passed += run_test("hello@world", "Hello@World");
	total++;
	passed += run_test("hello#world", "Hello#World");
	total++;
	passed += run_test("hello$world", "Hello$World");
	total++;
	passed += run_test("hello%world", "Hello%World");
	total++;
	passed += run_test("hello^world", "Hello^World");
	total++;
	passed += run_test("hello&world", "Hello&World");
	total++;
	passed += run_test("hello*world", "Hello*World");
	total++;
	passed += run_test("hello(world)", "Hello(World)");
	total++;
	passed += run_test("hello[world]", "Hello[World]");
	total++;
	passed += run_test("hello{world}", "Hello{World}");
	total++;
	passed += run_test("hello/world", "Hello/World");
	total++;
	passed += run_test("hello\\world", "Hello\\World");
	total++;
	passed += run_test("hello|world", "Hello|World");
	total++;
	passed += run_test("hello:world", "Hello:World");
	total++;
	passed += run_test("hello\"world", "Hello\"World");
	total++;
	passed += run_test("hello'world", "Hello'World");
	total++;
	passed += run_test("hello<world>", "Hello<World>");
	total++;
	passed += run_test("hello~world", "Hello~World");
	total++;
	passed += run_test("hello=world", "Hello=World");
	total++;
	passed += run_test("hello?world", "Hello?World");
	total++;
	passed += run_test("hello!world", "Hello!World");
	total++;
	passed += run_test("hello\tworld", "Hello\tWorld");
	total++;
	passed += run_test("hello\nworld", "Hello\nWorld");
	total++;

	/* --- Ayırıcı ile başlayan/biten stringler --- */
	passed += run_test("-hello", "-Hello");
	total++;
	passed += run_test("hello-", "Hello-");
	total++;
	passed += run_test("  hello", "  Hello");
	total++;
	passed += run_test("hello  ", "Hello  ");
	total++;
	passed += run_test("-----a", "-----A");
	total++;
	passed += run_test("a-----", "A-----");
	total++;

	/* --- Tek karakter / uç durumlar --- */
	passed += run_test("a", "A");
	total++;
	passed += run_test("A", "A");
	total++;
	passed += run_test("1", "1");
	total++;
	passed += run_test("-", "-");
	total++;
	passed += run_test("", "");
	total++;
	passed += run_test("   ", "   ");
	total++;
	passed += run_test("-----", "-----");
	total++;

	/* --- 42 exercise'daki orijinal örnek --- */
	passed += run_test("hi, how are you? 42words forty-two; fifty+and+one",
			"Hi, How Are You? 42words Forty-Two; Fifty+And+One");
	total++;

	/* --- Karışık büyük/küçük harf + ayırıcı kombinasyonları --- */
	passed += run_test("aB-Cd+eF", "Ab-Cd+Ef");
	total++;
	passed += run_test("ALREADY UPPER", "Already Upper");
	total++;
	passed += run_test("already lower", "Already Lower");
	total++;

	/* --- Sayı + harf + sayı karışık --- */
	passed += run_test("a1b2c3", "A1b2c3");
	total++;
	passed += run_test("1a2b3c", "1a2b3c");
	total++;

	printf("\n---------------------------------\n");
	printf("Sonuc: %d / %d test basarili\n", passed, total);
	printf("---------------------------------\n");

	return (0);
}