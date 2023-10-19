using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class AllInOne : MonoBehaviour
{
    // ROTATION VARIABLES
    private bool isDragging = false;
    private Vector2 initialTouchPosition;
    private Quaternion initialRotation;
    public float rotationSpeed = 1.0f;

    // ZOOM VARIABLES
    private float minZoom = 0.25f;  // Pienin mahdollinen zoom
    private float maxZoom = 2.0f;   // Suurin mahdollinen zoom
    private float initialPinchDistance;
    private float initialScale;

    // SHAKE VARIABLES
    private bool isShaking = false;
    private float shakeThreshold = 2.0f; // Muuta tarvittaessa
    private float rotationTime = 0.5f;   // Aika, joka kuluu kääntymiseen
    private Quaternion targetRotation = Quaternion.Euler(0, 180, 0);

    // TEXTMESH VARIABLES
    public float delayInSeconds = 2.0f; // Viive sekunteina
    public float hideDelayInSeconds = 2.0f;
    private GameObject textObject;

    // Taulukko sanoista, joista valita
    public string[] wordsToChooseFrom = { 
        "It is certain", 
        "It is decidedly so", 
        "Without a doubt", 
        "Yes definitely", 
        "You may rely on it", 
        "As I see it, yes", 
        "Most likely", 
        "Outlook good", 
        "Yes", 
        "Signs point to yes", 
        "Reply hazy, try again", 
        "Ask again later", 
        "Better not tell you now", 
        "Cannot predict now", 
        "Concentrate and ask again", 
        "Don't count on it", 
        "My reply is no", 
        "My sources say no", 
        "Outlook not so good", 
        "Very doubtful" 
    }; 


    // Start is called before the first frame update
    void Start()
    {
        initialRotation = transform.rotation; // Turha?

        // Etsii TextMesh-komponenttia tagin perusteella
        textObject = GameObject.FindGameObjectWithTag("Prediction");

        // Piilota teksti aluksi
        textObject.SetActive(false);
    }

    // Update is called once per frame
    void LateUpdate() // LateUpdate korjaa liikkeen glitsit yms.
    {
        if (Input.touchCount == 0)
        {
            CheckShake();
        }
        else if (Input.touchCount == 1)
        {
            BallRotation();
        }
        else if (Input.touchCount == 2)
        {
            PinchZoom();
        }
    }

    void BallRotation()
    {
        if (Input.touchCount == 1)
        {
            Touch touch = Input.GetTouch(0);

            switch (touch.phase)
            {
                case TouchPhase.Began:
                    isDragging = true;
                    initialTouchPosition = touch.position;
                    break;

                case TouchPhase.Moved:
                    if (isDragging)
                    {
                        Vector2 currentTouchPosition = touch.position;
                        Vector2 dragVector = currentTouchPosition - initialTouchPosition;

                        // Käännä palloa suhteessa dragVectorin liikkeeseen
                        float rotationX = dragVector.y * rotationSpeed * Time.deltaTime;
                        float rotationY = -dragVector.x * rotationSpeed * Time.deltaTime;

                        Quaternion xRotation = Quaternion.AngleAxis(rotationX, Vector3.right);
                        Quaternion yRotation = Quaternion.AngleAxis(rotationY, Vector3.up);

                        transform.rotation = initialRotation * xRotation * yRotation;
                    }
                    break;

                case TouchPhase.Ended:
                    isDragging = false;
                    initialRotation = transform.rotation; // Muista uusi asento
                    break;
            }
        }
        else
        {
            isDragging = false;
        }
    }

    void PinchZoom()
    {
        if (Input.touchCount == 2)
        {
            // Kosketusnäytön kahden sormen zoom
            Touch touch0 = Input.GetTouch(0);
            Touch touch1 = Input.GetTouch(1);

            if (touch0.phase == TouchPhase.Began || touch1.phase == TouchPhase.Began)
            {
                // Tallenna kosketuksen aloituspiste ja alkuperäinen etäisyys
                initialPinchDistance = Vector2.Distance(touch0.position, touch1.position);
                initialScale = transform.localScale.x;
            }
            else if (touch0.phase == TouchPhase.Moved || touch1.phase == TouchPhase.Moved)
            {
                // Laske zoom-tekijä ja rajoita se minZoom ja maxZoom välille
                float currentPinchDistance = Vector2.Distance(touch0.position, touch1.position);
                float scaleFactor = currentPinchDistance / initialPinchDistance;
                float newScale = Mathf.Clamp(initialScale * scaleFactor, minZoom, maxZoom);

                // Päivitä objektin skaala
                transform.localScale = new Vector3(newScale, newScale, newScale);
            }
        }
    }

    void CheckShake()
    {
        // Puhelimen ravistustarkistus
        if (Input.acceleration.sqrMagnitude >= shakeThreshold * shakeThreshold)
        {
            if (!isShaking)
            {
                isShaking = true;
                StartCoroutine(RotateToTarget());

                Invoke("TextVisible", delayInSeconds);
            }
        }
        else
        {
            isShaking = false;
        }
    }

    IEnumerator RotateToTarget()
    {
        float startTime = Time.time;
        Quaternion startRotation = transform.rotation;

        while (Time.time - startTime < rotationTime)
        {
            float journeyLength = (Time.time - startTime) / rotationTime;
            transform.rotation = Quaternion.Slerp(startRotation, targetRotation, journeyLength);
            yield return null;
        }

        initialRotation = transform.rotation; // Päivittää pallon asennon, ettei pugaa jos sitä yrittää liikuttaa
    }

    void TextVisible()
    {
        StartCoroutine(ShowRandomWord());
        textObject.SetActive(true);
    }

    void HideText()
    {
        // Piilota teksti
        textObject.SetActive(false);
    }

    IEnumerator ShowRandomWord()
    {
        // Arvo satunnainen indeksi taulukosta
        int randomIndex = Random.Range(0, wordsToChooseFrom.Length);

        // Valitse satunnainen sana
        string randomWord = wordsToChooseFrom[randomIndex];

        // Etsi TextMeshPro-komponentti tekstiobjektista
        TextMeshProUGUI textMesh = textObject.GetComponent<TextMeshProUGUI>();

        // Aseta satunnainen sana tekstikomponenttiin
        textMesh.text = randomWord;

        yield return new WaitForSeconds(delayInSeconds);

        // Ajoita piilotus
        //Invoke("HideText", hideDelayInSeconds);
        HideText();
    }
}

