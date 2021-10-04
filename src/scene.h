#pragma once

#include "light.h"
#include "camera.h"
#include "model.h"
#include "mesh.h"

#include <vector>

namespace Desperado {
	class Scene {
	public:
		Scene() {}

		std::vector<std::shared_ptr<DirectionalLight>> directionalLights;
		std::vector<std::shared_ptr<PointLight>> pointLights;
		std::vector<std::shared_ptr<ParallelogramLight>> parallelogramLights;
		std::vector<std::shared_ptr<Model>> models;
		std::vector<std::shared_ptr<Mesh>> meshes;

		std::shared_ptr<Camera> pCamera;

		//SVGF use
		glm::mat4 preViewMatrix = glm::mat4(1.0f);
		glm::mat4 preProjectionMatrix = glm::mat4(1.0f);

		uint32_t frameNum = 0;

		void SetCamera(std::shared_ptr<Camera> pC) {
			pCamera = pC;
		};
		void AddDirectionalLight(std::shared_ptr<DirectionalLight> l) {
			directionalLights.push_back(l);
		};
		void AddPointLight(std::shared_ptr<PointLight> l) {
			pointLights.push_back(l);
		};
		void AddParallelogramLight(std::shared_ptr<ParallelogramLight> l) {
			parallelogramLights.push_back(l);
		};
		void AddModel(std::shared_ptr<Model> m) {
			models.push_back(m);
		};
		void AddMesh(std::shared_ptr<Mesh> mesh) {
			meshes.push_back(mesh);
		};

		void DrawLights() {
			for (int i = 0; i < directionalLights.size(); i++) {
				auto light = directionalLights[i];

				glm::mat4 modelMatrix(1.0f);
				glm::mat4 viewMatrix(1.0f);
				glm::mat4 projectionMatrix(1.0f);

				TRStransform trans = light->entity->transform;

				modelMatrix = glm::translate(modelMatrix, trans.translate);

				modelMatrix = glm::scale(modelMatrix, trans.scale);

				if (trans.rotateAngle) {
					modelMatrix = glm::rotate(modelMatrix, trans.rotateAngle, trans.rotateAxis);
				}


				viewMatrix = pCamera->GetViewMatrix();
				projectionMatrix = pCamera->GetPerspectiveMatrix();

				auto shader = light->shader;
				shader->use();
				shader->setMat4("uModelMatrix", modelMatrix);
				shader->setMat4("uViewMatrix", viewMatrix);
				shader->setMat4("uProjectionMatrix", projectionMatrix);

				directionalLights[i]->Draw();
			}
			for (int i = 0; i < pointLights.size(); i++) {
				auto light = pointLights[i];

				glm::mat4 modelMatrix(1.0f);
				glm::mat4 viewMatrix(1.0f);
				glm::mat4 projectionMatrix(1.0f);

				TRStransform trans = light->entity->transform;

				modelMatrix = glm::translate(modelMatrix, trans.translate);

				modelMatrix = glm::scale(modelMatrix, trans.scale);

				if (trans.rotateAngle) {
					modelMatrix = glm::rotate(modelMatrix, trans.rotateAngle, trans.rotateAxis);
				}


				viewMatrix = pCamera->GetViewMatrix();
				projectionMatrix = pCamera->GetPerspectiveMatrix();

				auto shader = light->shader;
				shader->use();
				shader->setMat4("uModelMatrix", modelMatrix);
				shader->setMat4("uViewMatrix", viewMatrix);
				shader->setMat4("uProjectionMatrix", projectionMatrix);

				pointLights[i]->Draw();
			}
			for (int i = 0; i < parallelogramLights.size(); i++) {
				auto light = parallelogramLights[i];

				glm::mat4 modelMatrix(1.0f);
				glm::mat4 viewMatrix(1.0f);
				glm::mat4 projectionMatrix(1.0f);

				TRStransform trans = light->entity->transform;

				modelMatrix = glm::translate(modelMatrix, trans.translate);

				modelMatrix = glm::scale(modelMatrix, trans.scale);

				if (trans.rotateAngle) {
					modelMatrix = glm::rotate(modelMatrix, trans.rotateAngle, trans.rotateAxis);
				}


				viewMatrix = pCamera->GetViewMatrix();
				projectionMatrix = pCamera->GetPerspectiveMatrix();

				auto shader = light->shader;
				shader->use();
				shader->setMat4("uModelMatrix", modelMatrix);
				shader->setMat4("uViewMatrix", viewMatrix);
				shader->setMat4("uProjectionMatrix", projectionMatrix);

				parallelogramLights[i]->Draw();
			}
		}

		void DrawModels(Shader& shader) {
			for (int i = 0; i < models.size(); i++) {
				auto model = models[i];

				glm::mat4 modelMatrix(1.0f);
				glm::mat4 viewMatrix(1.0f);
				glm::mat4 projectionMatrix(1.0f);

				TRStransform trans = model->transform;

				modelMatrix = glm::translate(modelMatrix, trans.translate);

				modelMatrix = glm::scale(modelMatrix, trans.scale);
				if (trans.rotateAngle) {
					modelMatrix = glm::rotate(modelMatrix, trans.rotateAngle, trans.rotateAxis);
				}

				preViewMatrix = viewMatrix;
				preProjectionMatrix = projectionMatrix;

				viewMatrix = pCamera->GetViewMatrix();
				projectionMatrix = pCamera->GetPerspectiveMatrix();

				shader.use();
				shader.setMat4("model", modelMatrix);
				shader.setMat4("view", viewMatrix);
				shader.setMat4("projection", projectionMatrix);

				shader.setMat4("pre_view", preViewMatrix);
				shader.setMat4("pre_projection", preProjectionMatrix);

				models[i]->Draw(shader);
			}
		}

		void DrawMeshes(Shader& shader) {
			for (int i = 0; i < meshes.size(); i++) {
				auto mesh = meshes[i];

				glm::mat4 modelMatrix(1.0f);
				glm::mat4 viewMatrix(1.0f);
				glm::mat4 projectionMatrix(1.0f);

				TRStransform trans = mesh->transform;

				modelMatrix = glm::translate(modelMatrix, trans.translate);

				modelMatrix = glm::scale(modelMatrix, trans.scale);

				if (trans.rotateAngle) {
					modelMatrix = glm::rotate(modelMatrix, glm::radians(trans.rotateAngle), trans.rotateAxis);
				}


				viewMatrix = pCamera->GetViewMatrix();
				projectionMatrix = pCamera->GetPerspectiveMatrix();


				shader.use();
				shader.setMat4("uModelMatrix", modelMatrix);
				shader.setMat4("uViewMatrix", viewMatrix);
				shader.setMat4("uProjectionMatrix", projectionMatrix);
				meshes[i]->Draw(shader);
			}
		}
	};
}
