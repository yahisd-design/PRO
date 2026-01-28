export async function handler(event) {
  const data = JSON.parse(event.body || '{}');

  if (data.password === 'seconde2025') {
    return {
      statusCode: 200,
      body: 'ok'
    };
  }

  return {
    statusCode: 401,
    body: 'Unauthorized'
  };
}
