# ProgLab2.2-Automat
Programming Lab Project 2 made with Tiva™ C Series TM4C123G LaunchPad using Energia IDE

En az sayıda bozuk para verme problemi

Kaan Tecik - Oğuzhan Taşımaz
170201069 - 170201041

Bu readme.txt dosyası, En az sayıda bozuk para verme problemine aittir.
Bu paket, kaynak kodu ile aynı dizin içerisinde bulunacaktır.

1-PAKETİN İÇERİĞİ :
------------------
170201069-170201041.txt - Projenin tek dosyaya indirgenmiş salt kaynak kodu.
readme.txt - Bu dosya.
170201069-170201041.zip - Projenin kaynak kodunun ve yardımcı dosyaların ziplenmiş hali.
Rapor.pdf - Projenin raporu.
------------------


2-SİSTEM GEREKSİNİMLERİ :
------------------------
Energia - https://energia.nu
------------------------

3-PROJEYİ ÇALIŞTIRMAK :
-----------------------

Paket içeriğini, yukarıda görebilirsiniz.

Bu kod, bir adet Windows bir adet MacOS kurulu makinede çalıştırıldı.

Bu iki  durumda da kod, herhangi bir hata vermeksizin, daha önceden belirtilen
kriterlere uyhun çalıştırıldı.

Ön gereklilik:
Projenin çalıştırıldığı makinede gerekli kart güncellemeleri ve port
girişlerinin ayarlanması ve devrenin sorunsuz bağlanması beklenmektedir.

Projeyi çalıştırmak için Energia IDE'si kullanıldı.


LCD üzerindeki bağlantılar şu şekilde kullanılmalıdır:

LCD pin              Bağlandığı yer
 ---------------------------------
 01 - GND             GND, pot
 02 - VCC             +5V, pot
 03 - Contrast        Pot'un ortası
 04 - RS              (PB_0)
 05 - R/W             GND
 06 - EN              (PB_1)
 07 - DB0             GND
 08 - DB1             GND
 09 - DB2             GND
 10 - DB3             GND
 11 - DB4             (PB_4)
 12 - DB5             (PB_5)
 13 - DB6             (PB_6)
 14 - DB7             (PB_7)
 15 - BL+             +5V
 16 - BL-             GND


 Breadboard üzerindeki butonlar mikroişlemcinin şu portlarına yerleştirilmelidir:

 Buttons	 PHASE1		 PHASE2		PORTS
--------------------------------------------------------
 1 TL		-ÇAY 	 - 			(PD_2)
 
 50 Kuruş	-SU 	 - 			(PD_3)
 
 25 Kuruş	-BISKUVI - 			(PD_6)
 
 FINISH		-ENDOFPH1-	-ENDOFPH2- 	(PUSH2)
 
 TIVA-SOL			-CIKOLATA-	(PUSH1)
 
 SAGDAN4			-KAHVE	 -	(PD_7)
 
 EN-SOL				-RESET   -	(PA_2)
 
 
4-KODU DERLEMEK:
-----------------
Bilgisayarımızda kurulu olan Energia ile kodu kolayca derleyebiliriz.

Projeyi derlemek için "Yükle" butonuna tıklayabilirsiniz.

Derleme bittikten sonra 3-PROJEYİ ÇALIŞTIRMAK kısmındaki yönergeleri izleyerek
kodu çalıştırabilirsiniz.
----------------

5-PARAMETRELER :
----------------
Kodun çalışması için başlangıçta herhangi bir parametre gerekmiyor.
----------------

6-PROGRAMIN KULLANIMI :
-----------------------
En az sayıda bozuk para verme problemi, açılışında bakiye yükleme aşaması
ile başlar. 1TL eklemek için ekte belirtilen 1TL butonuna; 50 Kuruş eklemek
için 50 kuruş butonuna ve 25 Kuruş eklemek için 25 Kuruş butonuna tıklamak yeterlidir.

Bakiye yükleme işlemi bittikten sonra kullanıcının karşısına alabileceği 5 ürün çıkar :
-Su
-Çay
-Kahve
-Bisküvi
-Çikolata

Yukarıda belirtilen ürünlerden istediğini alıp işlemi sonlandırdıktan sonra
en kısa sayıda para üstü kullanıcıya verilir.
NOT:
Dikkat edilmesi gerekilen noktalardan biri kasada yeterli bakiye olup olmadığıdır.
Eğer bakiye yetersiz ise kasa bu durumda kullanıcıya para üstü vermeyecektir.
