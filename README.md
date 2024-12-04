# Child Process Uygulamaları
## 1.Child Process Oluşturma ve Yönetimi
Amaç:
Bu uygulama, bir child process oluşturmayı ve parent process ile child process arasındaki etkileşimi öğrenerek bu konuda pratik yapmayı hedeflemektedir.

Görev:
Bir child process oluşturma ve parent process ile etkileşim kurma.

Nasıl çalışır:
gcc -o gorev1 gorev1.c && ./gorev1
## 2.Child Process’lerde Hata Yönetimi
Amaç:
Bir	hata	durumu	simüle	ederek	child	process'lerde	abort()	ve	exit()	işlevlerinin	farkını	öğrenmek.

Görev:
Child process'lerde hata yönetimi ve çıkış durumlarının analizi.

Nasıl çalışır:
gcc -o gorev2 gorev2.c && ./gorev2
## 3.Paralel Child Process’lerle Çoklu Görev Yönetimi

Amaç:
Birden	fazla	child	process'in	paralel	olarak	nasıl	çalıştırılacağını	ve	bu	süreçlerin	
koordinasyonunun	nasıl	yapılacağını	öğrenmek.

Görev:
Paralel çalışan birden fazla child process oluşturma ve bunların koordinasyonu.

Nasıl çalışır:
gcc -o gorev3 gorev3.c && ./gorev3

