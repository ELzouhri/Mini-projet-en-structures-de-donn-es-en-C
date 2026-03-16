# Mini-projet-en-structures-de-donn-es-en-C

# 📚 Système de Gestion d'une Bibliothèque (C)

## 📌 Description
Ce projet est une application en langage **C** permettant de gérer un petit système de bibliothèque avec authentification des utilisateurs.

Le programme permet :
- l'authentification des utilisateurs
- la gestion des utilisateurs
- l'affichage des livres disponibles
- la distinction entre **administrateur** et **étudiant**

Les informations des utilisateurs peuvent être stockées dans un fichier texte et les mots de passe sont **cryptés** avant d'être enregistrés.

---

## 🛠 Technologies utilisées
- Langage : **C**
- Structures de données : **Listes chaînées**
- Fichiers : **fichier texte (.txt)**
- Concepts utilisés :
  - `struct`
  - `union`
  - `enum`
  - manipulation de fichiers (`fopen`, `fscanf`, `fprintf`)
  - chiffrement simple (cryptage César)

---

## 👤 Types d'utilisateurs

### 1️⃣ Administrateur
L'administrateur peut :

- afficher la liste des utilisateurs
- ajouter un utilisateur
- afficher la liste des livres
- se déconnecter

### 2️⃣ Étudiant
L'étudiant peut :

- afficher la liste des livres
- se déconnecter

---

## 🔐 Authentification

Le système permet de se connecter avec trois types d'identifiants :

- **CIN**
- **CNE**
- **APOGEE**

Chaque utilisateur possède :
- identifiant
- mot de passe
- nom
- prénom
- date de naissance
- type d'utilisateur

---

## 🔒 Sécurité

Les mots de passe sont **cryptés** avec une méthode simple basée sur le **chiffrement de César (+5)** avant d'être enregistrés dans le fichier.

Fonctions utilisées :
- `crypt()` : crypte le mot de passe
- `decrypt()` : décrypte le mot de passe

---

