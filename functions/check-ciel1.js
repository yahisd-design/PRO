export async function handler(event) {
  const { password } = JSON.parse(event.body || '{}');

  if (password === 'ciel1_2025') {
    return { statusCode: 200, body: 'ok' };
  }

  return { statusCode: 401, body: 'Unauthorized' };
}
