# FlightManagementSystem
Priority Queue Yapısı ile Uçuş Yönetim Sistemi

Projede oncelikli kuyruk kullanarak input dosyasından bilgiler alınmaya başlanır. Input dosyasından okunan sırayla talep edilen saat bos mu degil mi kontrol edilir. Eger talep edilen saat boş ise iniş için izin verilir.

Daha sonrasında gelen ucaklar ise onceliklerinden dolayı izin verilen saatin yerine geçebilir.

Önceliği düşük olan uçaklar her zaman aynı saatte talep edilen uçaklardan daha once inmedilir. Eger oncelikleri aynı ise ilk talep eden uçaga bakılmalıdır. 

Hiçbir uçagın aynı saatte inmemesini oncelikleri düşük (yani onemli) olan uçakların daha  once piste inebilmeleri için bir kuyruk yapısı olusturuldu.

Bu kuyruk yapısında maximum 24 uçak inis yapabilir. Kalkıs talep eden uçaklar ise iniş izni verilen saatten 1 saat sonra kalkış gerçeklesmelidir. 

Gecikmeler hesaba katılarak output.txt dosyasına yazdırılmıştır.

<img
  src="/images/1.png"
  alt="Alt text"
  title="Optional title"
  style="display: inline-block; margin: 0 auto;  width: 300px"> 
  
  <img
  src="/images/2.png"
  alt="Alt text"
  title="Optional title"
  style="display: inline-block; margin: 0 auto;  width: 300px"> 
