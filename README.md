# Hastane Randevu ve Raporlama Sistemi

Bu proje, C dilinde yazılmış bir hastane randevu ve raporlama sistemidir. Program, hasta ve doktor bilgileri yönetimi, randevu kayıtları oluşturma ve raporlama gibi temel işlevleri gerçekleştirir. Kullanıcılar, hastaları sisteme ekleyebilir, güncelleyebilir, silebilir ve listeyebilir. Ayrıca, doktorlar ve randevulara ilişkin raporlar oluşturulabilir.

![Hastane Yönetim Sistemi Arayüzü](https://hizliresim.com/4mi5ape)

## Özellikler

- **Hasta Yönetimi**: Hastaları sistemde kaydedebilir, bilgilerini güncelleyebilir, silebilir ve listeyebilirsiniz.
- **Randevu Kayıtları**: Hastanın randevu tarihi ve ilişkili telefon numarası gibi bilgileri kaydedilir.
- **Raporlama**: Hastalar ve doktorlar için raporlar oluşturulabilir.
- **Dosya İşlemleri**: Hastaların bilgileri, randevu kayıtları ve raporlar dosyalara kaydedilir ve dosyalardan okunabilir.

## Kullanılan Yapılar

Proje, hastalar (`struct Hasta`), doktorlar (`struct Doktor`) ve raporlar (`struct Rapor`) için üç ana yapı tanımını içerir. Her bir yapı, ilgili verileri ve bir sonraki düğümü işaret eden bir pointer içerir.

## Fonksiyonlar

- `hastaEkle`: Yeni bir hastayı listeye ekler.
- `hastaSil`: Belirli bir TC kimlik numarasına sahip hastayı listeden siler.
- `hastalariGoster`: Tüm hastaların listesini görüntüler.
- `hastaGuncelle`: Belirli bir TC kimlik numarasına sahip hastanın bilgilerini günceller.
- `hastaAra`: Belirli bir TC kimlik numarasına sahip hastayı arar.
- `hastaKaydet`: Yeni bir hastayı sisteme kaydeder.
- `dosyayaKaydet`: Tüm hasta kayıtlarını bir dosyaya yazar.
- `dosyadanOku`: Dosyadan hasta kayıtlarını okur ve listeye ekler.
- `raporEkle`: Bir hasta ve doktor için rapor ekler.
- `raporAl`: Bir hastaya ait rapor alır.
- `temelRaporlar`: Kullanıcıyı temel rapor işlemleri için bir menüye yönlendirir.

## Kullanım

Kullanıcı, konsol üzerinden interaktif komutlarla programı çalıştırır. Gerekli işlemler için belirtilen fonksiyonlar çağırılır ve kullanıcıdan veri girişi istenir.

## Kurulum

Projeyi kendi sistemlerinde çalıştırmak için kullanıcıların GCC gibi bir C derleyicisine ihtiyaçları vardır. Proje dosyalarını indirdikten sonra terminal veya komut satırı üzerinden aşağıdaki komutu çalıştırarak derleme işlemini gerçekleştirebilirler:

```sh
gcc -o hastane_sistemi.c
```

Bu adımdan sonra oluşturulan `hastane_sistemi` programını çalıştırarak sistemi kullanmaya başlayabilirler.

## Katkıda Bulunma

Projeye katkıda bulunmak isteyenler, GitHub üzerinden [fork](https://github.com/kullanici/hastane_sistemi/fork) yapabilir ve pull request gönderebilirler.

---

Projenin devam eden gelişimi için düzenli güncellemeler ve eklemeler yapılacaktır. İyileştirmeler ve önerileriniz için Issues sekmesini kullanabilirsiniz.

Not: Bu belge, örnek bir README dosyasıdır ve projenin gerçek bir GitHub sayfasını ifade etmez. `kullanici` ve `hastane_sistemi` yer tutuculardır ve gerçek kullanıcı adı ve proje adı ile değiştirilmelidir.
