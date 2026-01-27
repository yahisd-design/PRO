export default {
  async fetch(request) {
    const url = new URL(request.url)

    const protections = {
      "/seconde": "seconde2025",
      "/ciel1": "ciel1_2025",
      "/ciel2": "ciel2_2025",
    }

    for (const path in protections) {
      if (url.pathname.startsWith(path)) {
        const auth = request.headers.get("Authorization")

        if (!auth) {
          return new Response("Accès protégé", {
            status: 401,
            headers: { "WWW-Authenticate": 'Basic realm="Accès protégé"' }
          })
        }

        const encoded = auth.split(" ")[1]
        const decoded = atob(encoded)
        const password = decoded.split(":")[1]

        if (password !== protections[path]) {
          return new Response("Mot de passe incorrect", { status: 403 })
        }
      }
    }

    return fetch(request)
  }
}
