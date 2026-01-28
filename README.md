# 📚 Cours CIEL - Plateforme Pédagogique

Site web pour les cours d'Électronique & Systèmes Embarqués (Seconde, 1CIEL1, 1CIEL2)

## 📁 Structure du projet

```
/
├── index.html          # Page d'accueil avec navigation
├── style.css           # Styles communs à toutes les pages
├── seconde/
│   └── index.html      # Contenu Seconde
├── 1ciel1/
│   └── index.html      # Contenu 1CIEL1
└── 1ciel2/
    └── index.html      # Contenu 1CIEL2
```

## 🚀 Déploiement sur GitHub Pages + Cloudflare

### 1. Créer un dépôt GitHub

```bash
git init
git add .
git commit -m "Initial commit - Plateforme CIEL"
git branch -M main
git remote add origin https://github.com/VOTRE_USERNAME/cours-ciel.git
git push -u origin main
```

### 2. Activer GitHub Pages

1. Allez dans **Settings** > **Pages**
2. Source : **Deploy from a branch**
3. Branch : **main** / **root**
4. Cliquez sur **Save**

Votre site sera accessible à : `https://VOTRE_USERNAME.github.io/cours-ciel/`

## 🔐 Sécurisation avec Cloudflare

### Option 1 : Cloudflare Access (Protection par mot de passe)

1. **Créer un compte Cloudflare** et ajouter votre domaine
2. **Aller dans "Zero Trust" > "Access" > "Applications"**
3. **Créer une nouvelle application** :
   - Type : **Self-hosted**
   - Name : `Seconde CIEL`
   - Subdomain : `seconde`
   - Domain : `votredomaine.com`
   - Path : `/seconde/*`
   
4. **Configurer les règles d'accès** :
   - Policy name : `Élèves Seconde`
   - Action : **Allow**
   - Include : **Emails** → Ajouter les emails des élèves
   - OU Include : **One-time PIN** (code envoyé par email)

5. **Répéter pour 1CIEL1 et 1CIEL2**

### Option 2 : Cloudflare Workers (Authentification personnalisée)

Créez un Worker pour chaque niveau avec authentification :

```javascript
export default {
  async fetch(request) {
    const url = new URL(request.url);
    
    // Mots de passe par niveau
    const passwords = {
      '/seconde': 'seconde2025',
      '/1ciel1': 'ciel1_2025',
      '/1ciel2': 'ciel2_2025'
    };
    
    // Vérifier le cookie d'authentification
    const cookie = request.headers.get('Cookie');
    const authenticated = cookie && cookie.includes('auth=true');
    
    if (!authenticated) {
      // Afficher formulaire de connexion
      return new Response(loginForm, {
        headers: { 'content-type': 'text/html' }
      });
    }
    
    // Servir le contenu
    return fetch(request);
  }
}
```

### Option 3 : Cloudflare Page Rules (Simple redirection)

1. **Page Rules** > **Create Page Rule**
2. URL : `*votredomaine.com/seconde/*`
3. Setting : **Browser Integrity Check** + **Security Level: High**
4. Ajouter **IP Access Rules** pour limiter l'accès

## 🎯 Mots de passe des sections

Les mots de passe sont définis dans votre configuration Cloudflare (pas dans le code source pour plus de sécurité).

- **Seconde** : `seconde2025`
- **1CIEL1** : `ciel1_2025`
- **1CIEL2** : `ciel2_2025`

## 📝 Personnalisation

### Modifier les couleurs

Éditez `style.css` :

```css
:root {
    --primary: #00878F;    /* Couleur principale */
    --accent: #E47128;     /* Couleur d'accentuation */
}
```

### Ajouter du contenu

Éditez les fichiers `index.html` dans chaque dossier pour ajouter des cours, TP, ou projets.

## 👨‍🏫 Auteur

**Yahia Isddiken**  
Lycée CIEL - Année scolaire 2024-2025

## 📧 Contact

yahia.isddiken@lycee.fr

---

© 2024-2025 - Tous droits réservés
