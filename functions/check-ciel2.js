export async function onRequest({ request }) {
  const { password } = await request.json();

  if (password === "ciel2") {
    return new Response("OK", { status: 200 });
  }
  return new Response("Unauthorized", { status: 401 });
}
