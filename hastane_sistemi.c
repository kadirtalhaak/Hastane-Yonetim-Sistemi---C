/******************************************************************************

github.com/kadirtalhaak

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hasta
{
  char TcNo[21];
  char Ad[31];
  char Soyad[31];
  char RandevuTarihi[21];
  char TelefonNo[21];
  struct Hasta *sonraki;
};

typedef struct Hasta Hasta;

struct Doktor
{
  char Ad[31];
  char Soyad[31];
  char Brans[31];
  struct Doktor *sonraki;
};

typedef struct Doktor Doktor;

struct Rapor
{
  char TcNo[21];
  char Ad[31];
  char Soyad[31];
  char RandevuTarihi[21];
  char TelefonNo[21];
  char DoktorAd[31];
  char DoktorSoyad[31];
  char DoktorBrans[31];
  struct Rapor *sonraki;
};

typedef struct Rapor Rapor;

void
hastaEkle (Hasta ** bas, Hasta * yeniHasta)
{
  if (*bas == NULL)
    {
      *bas = yeniHasta;
    }
  else
    {
      Hasta *temp = *bas;
      while (temp->sonraki != NULL)
	{
	  temp = temp->sonraki;
	}
      temp->sonraki = yeniHasta;
    }
}

void
dosyaKapat (FILE * dosya)
{
  fclose (dosya);
}

void
dosyayaKaydet (Hasta * bas)
{
  FILE *dosya = fopen ("hasta_randevu_kayitlari.txt", "w");
  if (dosya == NULL)
    {
      perror ("Dosya acma hatasi");
      exit (EXIT_FAILURE);
    }

  while (bas != NULL)
    {
      fprintf (dosya, "%s\t%s %s\t%s\t%s\n", bas->TcNo, bas->Ad, bas->Soyad,
	       bas->RandevuTarihi, bas->TelefonNo);
      bas = bas->sonraki;
    }

  dosyaKapat (dosya);
  printf ("\nKayitlar dosyaya basariyla kayit edildi!\n");
}

void
hastaSil (Hasta ** bas, const char *tcNo)
{
  Hasta *temp = *bas;
  Hasta *onceki = NULL;

  while (temp != NULL && strcmp (temp->TcNo, tcNo) != 0)
    {
      onceki = temp;
      temp = temp->sonraki;
    }

  if (temp == NULL)
    {
      printf ("\nHastahane de belirtilen hasta bulunamadi!\n");
      return;
    }

  if (onceki == NULL)
    {
      *bas = temp->sonraki;
    }
  else
    {
      onceki->sonraki = temp->sonraki;
    }

  free (temp);
  printf ("\nHastahane de belirtilen basariyla silindi!\n");
}

void
hastalariGoster (Hasta * bas)
{
  printf ("\nHastahane de belirtilen hasta kayitlari:\n\n");

  while (bas != NULL)
    {
      printf ("%s\t%s %s\t%s\t%s\n", bas->TcNo, bas->Ad, bas->Soyad,
	      bas->RandevuTarihi, bas->TelefonNo);
      bas = bas->sonraki;
    }
}

void
hastaGuncelle (Hasta * bas, const char *tcNo)
{
  Hasta *temp = bas;

  while (temp != NULL && strcmp (temp->TcNo, tcNo) != 0)
    {
      temp = temp->sonraki;
    }

  if (temp == NULL)
    {
      printf ("\nHastahane de belirtilen hasta bulunamadi!\n");
      return;
    }

  printf ("\nYeni bilgileri girin:\n");

  printf ("Adi: ");
  scanf ("%30s", temp->Ad);

  printf ("Soyadi: ");
  scanf ("%30s", temp->Soyad);

  printf ("Randevu tarihi (format: [gg/aa/yy]): ");
  scanf ("%20s", temp->RandevuTarihi);

  printf ("Telefon no (Orn: 25078xxxxxx): ");
  scanf ("%20s", temp->TelefonNo);

  printf ("\nHastahane de belirtilen hasta basariyla gC<ncellendi!\n");
}

void
hastaAra (Hasta * bas, const char *tcNo)
{
  Hasta *temp = bas;

  while (temp != NULL && strcmp (temp->TcNo, tcNo) != 0)
    {
      temp = temp->sonraki;
    }

  if (temp == NULL)
    {
      printf ("\nHastahane de belirtilen hasta bulunamadi!\n");
      return;
    }

  printf ("\nHastahane de belirtilen hasta bilgileri:\n");
  printf ("%s\t%s %s\t%s\t%s\n", temp->TcNo, temp->Ad, temp->Soyad,
	  temp->RandevuTarihi, temp->TelefonNo);
}

void
hastaKaydet (Hasta ** bas)
{
  Hasta *yeniHasta = (Hasta *) malloc (sizeof (Hasta));

  printf ("\nTC Kimlik No: ");
  scanf ("%20s", yeniHasta->TcNo);

  printf ("AdD1: ");
  scanf ("%30s", yeniHasta->Ad);

  printf ("SoyadD1: ");
  scanf ("%30s", yeniHasta->Soyad);

  printf ("Randevu tarihi (format: [gg/aa/yy]): ");
  scanf ("%20s", yeniHasta->RandevuTarihi);

  printf ("Telefon no (C6rn: 25078xxxxxx): ");
  scanf ("%20s", yeniHasta->TelefonNo);

  yeniHasta->sonraki = NULL;

  hastaEkle (bas, yeniHasta);

  printf ("\nHastahane de belirtilen hasta basariyla kaydedildi!\n");
}

void
dosyadanOku (Hasta ** bas)
{
  FILE *dosya = fopen ("hasta_randevu_kayitlari.txt", "r");
  if (dosya == NULL)
    {
      printf ("Dosya acma hatasi!\n");
      return;
    }

  while (1)
    {
      Hasta *yeniHasta = (Hasta *) malloc (sizeof (Hasta));
      int okumaSonuc =
	fscanf (dosya, "%s\t%s %s\t%s\t%s\n", yeniHasta->TcNo, yeniHasta->Ad,
		yeniHasta->Soyad, yeniHasta->RandevuTarihi,
		yeniHasta->TelefonNo);

      if (okumaSonuc == EOF)
	{
	  free (yeniHasta);
	  break;
	}

      if (okumaSonuc != 5)
	{
	  printf ("Dosya okuma hatasi!\n");
	  dosyaKapat (dosya);
	  exit (EXIT_FAILURE);
	}

      yeniHasta->sonraki = NULL;
      hastaEkle (bas, yeniHasta);
    }

  dosyaKapat (dosya);
  printf ("\nHastahane de belirtilen kayitlar dosyadan basariyla okundu!\n");
}

void
raporEkle (Rapor ** bas, Hasta * hasta, Doktor * doktor)
{
  Rapor *yeniRapor = (Rapor *) malloc (sizeof (Rapor));

  strcpy (yeniRapor->TcNo, hasta->TcNo);
  strcpy (yeniRapor->Ad, hasta->Ad);
  strcpy (yeniRapor->Soyad, hasta->Soyad);
  strcpy (yeniRapor->RandevuTarihi, hasta->RandevuTarihi);
  strcpy (yeniRapor->TelefonNo, hasta->TelefonNo);
  strcpy (yeniRapor->DoktorAd, doktor->Ad);
  strcpy (yeniRapor->DoktorSoyad, doktor->Soyad);
  strcpy (yeniRapor->DoktorBrans, doktor->Brans);

  yeniRapor->sonraki = NULL;

  if (*bas == NULL)
    {
      *bas = yeniRapor;
    }
  else
    {
      Rapor *temp = *bas;
      while (temp->sonraki != NULL)
	{
	  temp = temp->sonraki;
	}
      temp->sonraki = yeniRapor;
    }

  printf ("\nRapor basariyla eklendi!\n");
}

void
raporAl (Hasta * hastaBas, Doktor * doktorBas, Rapor ** raporBas)
{
  char tcNo[21];
  printf ("\nHastahane de belirtilen hasta TC Kimlik No girin: ");
  scanf ("%20s", tcNo);

  Hasta *tempHasta = hastaBas;
  Doktor *tempDoktor = doktorBas;

  while (tempHasta != NULL && strcmp (tempHasta->TcNo, tcNo) != 0)
    {
      tempHasta = tempHasta->sonraki;
    }

  while (tempDoktor != NULL)
    {
      break;
    }

  if (tempHasta == NULL)
    {
      printf ("\nHastahane de belirtilen hasta bulunamadi!\n");
      return;
    }

  raporEkle (raporBas, tempHasta, tempDoktor);
}

void
temelRaporlar (Hasta * hastaBas, Doktor * doktorBas, Rapor ** raporBas)
{
  int secim;

  do
    {
      printf ("\n----- Rapor D0slemleri -----\n");
      printf ("1. Rapor Al\n");
      printf ("0. Cikis\n");
      printf ("Seciminiz: ");
      scanf ("%d", &secim);

      switch (secim)
	{
	case 1:
	  raporAl (hastaBas, doktorBas, raporBas);
	  break;
	case 0:
	  printf ("\nRapor islemlerinden cikiliyor yazdiliyor..\n");
	  break;
	default:
	  printf ("\nGecersiz secim!\n");
	}
    }
  while (secim != 0);
}

int
main ()
{
  Hasta *hastaBas = NULL;
  Doktor *doktorBas = NULL;
  Rapor *raporBas = NULL;

  int secim;
  char tcNo[21];

  dosyadanOku (&hastaBas);

  do
    {
      printf ("\n----- Hastane Yonetim Sistemi Menusu -----\n");
      printf ("1. Hastahaneye Yeni Hasta Kaydet\n");
      printf ("2. Hastalari Goster\n");
      printf ("3. Hasta Guncelle\n");
      printf ("4. Hasta Ara\n");
      printf ("5. Hasta Sil\n");
      printf ("6. Rapor D0slemleri\n");
      printf ("0. Cikis Yap\n");
      printf ("Seciminiz: ");
      scanf ("%d", &secim);

      switch (secim)
	{
	case 1:
	  hastaKaydet (&hastaBas);
	  break;
	case 2:
	  hastalariGoster (hastaBas);
	  break;
	case 3:
	  printf ("\nHasta TC Kimlik No girin: ");
	  scanf ("%20s", tcNo);
	  hastaGuncelle (hastaBas, tcNo);
	  break;
	case 4:
	  printf ("\nHasta TC Kimlik No girin: ");
	  scanf ("%20s", tcNo);
	  hastaAra (hastaBas, tcNo);
	  break;
	case 5:
	  printf ("\nHasta TC Kimlik No girin: ");
	  scanf ("%20s", tcNo);
	  hastaSil (&hastaBas, tcNo);
	  break;
	case 6:
	  temelRaporlar (hastaBas, doktorBas, &raporBas);
	  break;
	case 0:
	  printf ("\nSistemden Cikiliyor...\n");
	  break;
	default:
	  printf ("\nGecersiz secim!\n");
	}
    }
  while (secim != 0);

  dosyayaKaydet (hastaBas);

  while (hastaBas != NULL)
    {
      Hasta *temp = hastaBas;
      hastaBas = hastaBas->sonraki;
      free (temp);
    }

  while (doktorBas != NULL)
    {
      Doktor *tempDoktor = doktorBas;
      doktorBas = doktorBas->sonraki;
      free (tempDoktor);
    }

  while (raporBas != NULL)
    {
      Rapor *tempRapor = raporBas;
      raporBas = raporBas->sonraki;
      free (tempRapor);
    }

  return 0;
}
