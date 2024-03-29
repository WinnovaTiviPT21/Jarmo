using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using System;
using Random = UnityEngine.Random;

public class AllInOne : MonoBehaviour
{
    // ROTATION VARIABLES
    private bool isDragging = false;
    private bool controlDisabled;
    private Vector2 initialTouchPosition;
    private Quaternion initialRotation;
    public float rotationSpeed = 5.0f;

    // ZOOM VARIABLES
    private float minZoom = 0.25f;
    private float maxZoom = 2.0f;
    private float initialPinchDistance;
    private float initialScale;

    // SHAKE VARIABLES
    private bool isShaking = false;
    private float shakeThreshold = 3.0f;
    private float rotationTime = 0.5f;
    private Quaternion targetRotation = Quaternion.Euler(0, 180, 0);

    // TEXTMESH VARIABLES
    public float enableDelayInSeconds = 1.0f;
    public float disableDelayInSeconds = 2.0f;
    public TextMeshPro textMesh; // Tai TMP_Text (tekstikomponentti)

    // TAULUKOT ENNUSTUKSISTA
    public string[] predictionsEn = { 
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

    public string[] predictionsFi = {
        "Se on varmaa",
        "Se on ehdottomasti niin",
        "Ei ep�ilyst�k��n",
        "Ehdottomasti kyll�",
        "Voit luottaa siihen",
        "Niin kuin min� sen n�en, kyll�",
        "Hyvin todenn�k�ist�",
        "N�kym�t ovat hyv�t",
        "Kyll�",
        "Merkit viittaavat my�nt�v�sti",
        "Vastaus on ep�selv�, kysy uudelleen",
        "Kysy my�hemmin uudelleen",
        "Parasta, etten kerro sit� juuri nyt",
        "En voi ennustaa nyt",
        "Keskity ja kysy uudelleen",
        "�l� luota siihen",
        "Vastaukseni on ei",
        "L�hteideni mukaan ei.",
        "N�kym�t eiv�t ole kovin hyv�t",
        "Se on Hyvin ep�todenn�k�ist�"
    };


    // Start is called before the first frame update
    void Start()
    {
        initialRotation = transform.rotation; // Turha?
        textMesh.enabled = false; // Piilottaa tekstin alussa
    }

    // Update is called once per frame
    // LateUpdate korjaa liikkeen glitsit yms.
    void LateUpdate() 
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
        // Tarkista, onko vain yksi kosketus ja ohjaus ei ole poistettu k�yt�st�
        if (Input.touchCount == 1 && !controlDisabled)
        {
            // Hae ensimm�inen kosketus
            Touch touch = Input.GetTouch(0);

            // K�sittele kosketuksen vaiheet
            switch (touch.phase)
            {
                // Kosketus aloitettu
                case TouchPhase.Began:
                    isDragging = true;
                    initialTouchPosition = touch.position;
                    break;

                // Kosketusta liikutetaan
                case TouchPhase.Moved:
                    if (isDragging)
                    {
                        // Hae nykyinen kosketuskohta
                        Vector2 currentTouchPosition = touch.position;
                        // Laske vetovektori
                        Vector2 dragVector = currentTouchPosition - initialTouchPosition;

                        // Laske rotaatio x- ja y-akseleilla perustuen vetovektoriin
                        float rotationX = dragVector.y * rotationSpeed * Time.deltaTime;
                        float rotationY = -dragVector.x * rotationSpeed * Time.deltaTime;

                        // Luo rotaatiot ymp�ri x- ja y-akseleita
                        Quaternion xRotation = Quaternion.AngleAxis(rotationX, Vector3.right);
                        Quaternion yRotation = Quaternion.AngleAxis(rotationY, Vector3.up);

                        // P�ivit� pallon rotaatio alkuper�isen rotaation avulla
                        transform.rotation = initialRotation * xRotation * yRotation;
                    }
                    break;

                // Kosketus p��ttyy
                case TouchPhase.Ended:
                    isDragging = false;
                    initialRotation = transform.rotation;
                    break;
            }
        }
        else
        {
            // Jos ei ole yht� kosketusta tai ohjaus on poistettu k�yt�st�, aseta isDragging ep�todeksi
            isDragging = false;
        }
    }

    // Pallon liikuttaminen pilkottuna pienempiin funktioihin
    /*
    void BallRotation()
    {
        // Tarkistetaan, onko kosketuksia vain yksi ja ohjaus ei ole poistettu k�yt�st�.
        if (Input.touchCount == 1 && !controlDisabled)
        {
            HandleSingleTouchInput(); // K�sitell��n yhden kosketuksen sy�tt�.
        }
        else
        {
            isDragging = false; // Jos kosketuksia on useampia tai ohjaus on poistettu k�yt�st�, asetetaan raahaaminen pois p��lt�.
        }
    }

    void HandleSingleTouchInput()
    {
        Touch touch = Input.GetTouch(0); // Haetaan ensimm�inen kosketus.

        switch (touch.phase)
        {
            case TouchPhase.Began:
                HandleTouchBegan(touch); // K�sitell��n kosketuksen alkuvaihe.
                break;

            case TouchPhase.Moved:
                HandleTouchMoved(touch); // K�sitell��n kosketuksen liikevaihe.
                break;

            case TouchPhase.Ended:
                HandleTouchEnded(); // K�sitell��n kosketuksen p��ttymisvaihe.
                break;
        }
    }

    void HandleTouchBegan(Touch touch)
    {
        isDragging = true; // Asetetaan raahaaminen p��lle.
        initialTouchPosition = touch.position; // Tallennetaan alkuper�inen kosketuskohta.
    }

    void HandleTouchMoved(Touch touch)
    {
        if (isDragging)
        {
            Vector2 currentTouchPosition = touch.position;
            Vector2 dragVector = currentTouchPosition - initialTouchPosition;

            RotateBallWithDrag(dragVector); // K�sitell��n raahaaminen kutsuen funktiota "RotateBallWithDrag".
        }
    }

    void HandleTouchEnded()
    {
        isDragging = false; // Kun kosketus p��ttyy, asetetaan raahaaminen pois p��lt�.
        initialRotation = transform.rotation; // Tallennetaan alkuper�inen rotaatio.
    }

    void RotateBallWithDrag(Vector2 dragVector)
    {
        // Lasketaan rotaatioarvot raahaamisen perusteella ja sovelletaan ne objektiin.
        float rotationX = dragVector.y * rotationSpeed * Time.deltaTime;
        float rotationY = -dragVector.x * rotationSpeed * Time.deltaTime;

        Quaternion xRotation = Quaternion.AngleAxis(rotationX, Vector3.right);
        Quaternion yRotation = Quaternion.AngleAxis(rotationY, Vector3.up);

        transform.rotation = initialRotation * xRotation * yRotation;
    }*/

    void PinchZoom()
    {
        // Tarkista, onko n�yt�ll� tarkalleen kaksi kosketusta
        if (Input.touchCount == 2)
        {
            // Hae tiedot kahdesta kosketuksesta
            Touch touch0 = Input.GetTouch(0);
            Touch touch1 = Input.GetTouch(1);

            // Tarkista, onko jompikumpi kosketuksista juuri alkanut
            if (touch0.phase == TouchPhase.Began || touch1.phase == TouchPhase.Began)
            {
                // Laske kahden kosketuksen v�linen alkuet�isyys
                initialPinchDistance = Vector2.Distance(touch0.position, touch1.position);

                // Tallenna kohteen alkuper�inen skaala
                initialScale = transform.localScale.x;
            }
            // Tarkista, liikkuuko jompikumpi kosketuksista juuri
            else if (touch0.phase == TouchPhase.Moved || touch1.phase == TouchPhase.Moved)
            {
                // Laske kahden kosketuksen v�linen nykyinen et�isyys
                float currentPinchDistance = Vector2.Distance(touch0.position, touch1.position);

                // Laske skaalakerroin et�isyyden muutoksen perusteella
                float scaleFactor = currentPinchDistance / initialPinchDistance;

                // Laske uusi skaala arvo m��ritettyjen rajojen sis�ll�
                float newScale = Mathf.Clamp(initialScale * scaleFactor, minZoom, maxZoom);

                // Sovella uutta skaalaa kohteen muokkaamiseen
                transform.localScale = new Vector3(newScale, newScale, newScale);
            }
        }
    }

    // T�m� funktio tarkistaa laitteen t�rin�n ja k�ynnist�� tarvittavat toimet, jos t�rin� ylitt�� kynnysarvon.
    void CheckShake()
    {
        // Tarkista, onko laite kokenut riitt�v�n voimakasta t�rin�� tai onko k�ytt�j� painanut hiiren vasenta painiketta.
        if (Input.acceleration.sqrMagnitude >= shakeThreshold * shakeThreshold || Input.GetMouseButtonDown(0))
        {
            // Jos laite t�risee ja ei ole jo t�rin�n aikana k�ynniss� olevia toimintoja, aloita toiminnot.
            if (!isShaking)
            {
                StartCoroutine(RotateToTarget());  // K�ynnist� funktio, joka k��nt�� jotain kohti t�rin�n yhteydess�.
                StartCoroutine(Prediction());     // K�ynnist� ennustustoiminto t�rin�n yhteydess�.
            }
        }
        else
        {
            // Jos t�rin� ei en�� ole voimassa, aseta isShaking-muuttuja todeksi.
            isShaking = false;
        }
    }

    // K��nt�� objektin n�yt�n oikeeseen suuntaan
    IEnumerator RotateToTarget()
    {
        // Asetetaan kontrolli pois p��lt�, jotta ohjaus ei h�iritse kiertoliikett�
        controlDisabled = true;

        // Tallennetaan aloitusaika
        float startTime = Time.time;

        // Tallennetaan alkuper�inen rotaatio
        Quaternion startRotation = transform.rotation;

        // K�yd��n l�pi liikeaika (rotationTime) ajan
        while (Time.time - startTime < rotationTime)
        {
            // Lasketaan, kuinka pitk�lle ollaan matkattu matkasta (0.0 - 1.0)
            float journeyLength = (Time.time - startTime) / rotationTime;

            // K�ytet��n Slerp-menetelm�� saavuttaaksemme tasaisen kiertoliikkeen
            transform.rotation = Quaternion.Slerp(startRotation, targetRotation, journeyLength);

            // Odota seuraava p�ivityskehys
            yield return null;

            // P�ivitet��n alkuper�inen rotaatio uusimmaksi rotaatioksi
            initialRotation = transform.rotation;
        }

        // Kiertoliike on valmis, joten laitetaan kontrolli takaisin p��lle
        controlDisabled = false;
    }

    // Enumerator-funktio, joka k�sittelee ennusteen
    IEnumerator Prediction()
    {
        // Tarkista, onko textMesh-komponentti poistettu k�yt�st�
        if (!textMesh.enabled)
        {
            // Valitse satunnainen indeksi ennusteiden joukosta
            int randomIndex = Random.Range(0, predictionsFi.Length);

            // Hae satunnainen sana ennusteista
            string randomWord = predictionsFi[randomIndex];

            // Aseta satunnainen sana textMesh-tekstikomponenttiin
            textMesh.text = randomWord;

            // Odota hetki ennen kuin kytkee textMesh-komponentin p��lle
            yield return new WaitForSeconds(enableDelayInSeconds);
            textMesh.enabled = true;

            // Odota toinen hetki ennen kuin kytkee textMesh-komponentin pois p��lt�
            yield return new WaitForSeconds(disableDelayInSeconds);
            textMesh.enabled = false;

            // Merkitse, ett� kontrolli ei ole poistettu k�yt�st�
            controlDisabled = false;
        }
    }
}